#include "stdafx.h"
#include "Controller.h"


Controller::Controller()
{
	conPoint = new ConnectionModbusPoint(NULL);
}

int Controller::initialize()
{
	data = { "127.0.0.1", 502 };

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

	return 0;
}

void Controller::simulate() {

	int status_connection = conPoint->openConnection(ConnectionModbusPoint::createPoint(tcp, &data));
	if (status_connection != -1) {
		uint16_t commands_regs[10];
		uint16_t read_regs[18];
		uint16_t write_regs[34];
		uint16_t alarm_regs[13];

		int count_command_regs = conPoint->readRegisters(0, 10, commands_regs);
		int count_read_regs = conPoint->readRegisters(160, 18, read_regs);

		if (count_command_regs == -1 || count_read_regs == -1) {
			printf("not read registers\n");
			return;
		}

		cr->setAll(commands_regs);
		rr->setAll(read_regs);

		for (int i = 0; i < COUNT_DEVICES; i++)
			devices[i]->process();

		wr->getAll(write_regs);
		ar->getAll(alarm_regs);

		int count_write_regs = conPoint->writeRegisters(64, 34, write_regs);
		int count_alarm_regs = conPoint->writeRegisters(224, 13, alarm_regs);

		if (count_write_regs == -1 || count_alarm_regs == -1)
			printf("not write registers\n");

		conPoint->closeConnection();

	} else {
		printf("cannot connection\n");
	}

}

Controller::~Controller()
{
	if (conPoint != NULL)
		delete conPoint;
	
	for (int i = 0; i < COUNT_DEVICES; i++)
		if (devices[i] != NULL)
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
