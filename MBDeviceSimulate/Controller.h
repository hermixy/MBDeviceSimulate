#pragma once

#include "devices.h"
#include "connection.h"

#define COUNT_DEVICES 3

class Controller
{
public:
	Controller();
	int initialize();
	void simulate();
	~Controller();

private:
	Device *devices[COUNT_DEVICES];
	ConnectionModbusPoint *conPoint;
	ReadRegisters *rr;
	WriteRegisters *wr;
	AlarmRegisters *ar;
	CommandRegisters *cr;
	struct TCPData data;
};
