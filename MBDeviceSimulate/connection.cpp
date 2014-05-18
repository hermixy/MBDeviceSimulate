#include "stdafx.h"
#include "connection.h"


ConnectionModbusPoint::ConnectionModbusPoint(modbus_t *ctx)
{
	this->ctx = ctx;
}

int ConnectionModbusPoint::openConnection()
{
	return modbus_connect(ctx);
}

int ConnectionModbusPoint::readRegisters(int address, int cnt, uint16_t *dest)
{
	return modbus_read_registers(ctx, address, cnt, dest);
}

int ConnectionModbusPoint::writeRegisters(int address, int cnt, uint16_t *src)
{
	return modbus_write_registers(ctx, address, cnt, src);
}

ConnectionModbusPoint::~ConnectionModbusPoint()
{
	modbus_close(ctx);
	modbus_free(ctx);
}

modbus_t * ConnectionModbusPoint::createPoint(TypeConnection type, void *data)
{
	if (type == tcp) {
		TCPData *tcpData = (TCPData *) data;
		return modbus_new_tcp(tcpData->host, tcpData->port);
	}

	return NULL;
}
