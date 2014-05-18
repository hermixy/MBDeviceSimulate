#include "stdafx.h"
#include "Controller.h"


Controller::Controller()
{
	status_init = 1;
}

int Controller::initialize()
{
	struct TCPData data = { "127.0.0.1", 502 };
	modbus_t *ctx = ConnectionModbusPoint::createPoint(tcp, &data);
	if (ctx != NULL) {
		conPoint = new ConnectionModbusPoint(ctx);
		int status = conPoint->openConnection();
		if (status != 0) {
			fprintf(stderr, "Error: %s\n", modbus_strerror(errno));
			return 1;
		}

		rr = new ReadRegisters();
		wr = new WriteRegisters();
		ar = new AlarmRegisters();
		cr = new CommandRegisters();

		Context context;
		context.type = CONSTANT;
		context.status = 1;

		devices[0] = new DeviceHeaterMain(rr, wr, ar, cr, context);
		devices[1] = new DeviceHeaterGround(rr, wr, ar, cr, context);
		devices[2] = new DeviceHeaterBackGround(rr, wr, ar, cr, context);

	} else {
		fprintf(stderr, "Error: %s\n", modbus_strerror(errno));
		return 1;

	}

	status_init = 0;
	return 0;
}

void Controller::simulate() {
	if (status_init == 0) {
		uint16_t commands_regs[10];
		uint16_t read_regs[18];
		uint16_t write_regs[34];
		uint16_t alarm_regs[13];

		conPoint->readRegisters(0, 10, commands_regs);
		conPoint->readRegisters(160, 18, read_regs);

		cr->setAll(commands_regs);
		rr->setAll(read_regs);

		for (int i = 0; i < COUNT_DEVICES; i++)
			devices[i]->process();

		wr->getAll(write_regs);
		ar->getAll(alarm_regs);

		conPoint->writeRegisters(64, 34, write_regs);
		conPoint->writeRegisters(224, 13, alarm_regs);
	}
}

Controller::~Controller()
{
	if (conPoint != NULL)
		delete conPoint;
	
	for (int i = 0; i < COUNT_DEVICES; i++)
		delete devices[i];

	if (rr != NULL)
		delete rr;
	if (wr != NULL)
		delete wr;
	if (ar != NULL)
		delete ar;
	if (cr != NULL)
		delete cr;
}
