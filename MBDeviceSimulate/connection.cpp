#include "stdafx.h"
#include "connection.h"


ConnectionModbusPoint::ConnectionModbusPoint(modbus_t *ctx)
{
	this->ctx = ctx;
}

int ConnectionModbusPoint::openConnection()
{
	if (ctx != NULL)
		return modbus_connect(ctx);
	return -1;
}

int ConnectionModbusPoint::openConnection(modbus_t *ctx)
{
	this->ctx = ctx;
	return this->openConnection();
}

void ConnectionModbusPoint::closeConnection() 
{
	if (ctx != NULL) {
		modbus_close(ctx);
		modbus_free(ctx);
	}
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
	closeConnection();
}

modbus_t * ConnectionModbusPoint::createPoint(TypeConnection type, void *data)
{
	if (type == tcp) {
		TCPData *tcpData = (TCPData *) data;
		return modbus_new_tcp(tcpData->host, tcpData->port);
	}

	return NULL;
}
