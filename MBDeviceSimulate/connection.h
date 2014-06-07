#pragma once

#include "modbus.h"

enum TypeConnection {tcp};

struct TCPData {
	char *host;
	int port;
};


class ConnectionModbusPoint
{
public:
	ConnectionModbusPoint(modbus_t *ctx);
	int openConnection();
	int openConnection(modbus_t *ctx);
	void closeConnection();
	int readRegisters(int address, int cnt, uint16_t *dest);
	int writeRegisters(int address, int cnt, uint16_t *src);
	~ConnectionModbusPoint();

	static modbus_t * createPoint(TypeConnection type, void *data);
private:
	modbus_t *ctx;
};

