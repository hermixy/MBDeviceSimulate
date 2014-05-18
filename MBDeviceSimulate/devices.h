#pragma once


#include "ReadRegisters.h"
#include "AlarmRegisters.h"
#include "WriteRegisters.h"
#include "CommandRegisters.h"
#include "modbus.h"
#include "Constants.h"

enum TypeSimulate {RANDOM, TOGGLE, CONSTANT};
struct Context
{
	TypeSimulate type;
	int status;
};

class Device
{
public:
	Device(ReadRegisters *rr, WriteRegisters *wr, AlarmRegisters *ar, CommandRegisters *cr, Context context) : rr(rr), wr(wr),
		ar(ar), cr(cr), context(context), is_on(0){};
	virtual void process() {};
	virtual ~Device() {};

protected:
	virtual void on() { is_on = 1; };
	virtual void off() { is_on = 0; };
	virtual void simulate_status() {};

	ReadRegisters *rr;
	WriteRegisters *wr;
	AlarmRegisters *ar;
	CommandRegisters *cr;
	Context context;
	uint16_t is_on;
};

class DeviceHeaterMain : public Device
{
public:
	DeviceHeaterMain(ReadRegisters *rr, WriteRegisters *wr, AlarmRegisters *ar, CommandRegisters *cr, Context context) :
		Device(rr, wr, ar, cr, context) {};
	virtual void process();
	virtual ~DeviceHeaterMain() {};

protected:
	virtual void on() { Device::on(); };
	virtual void off();
	virtual void simulate_status();
};

class DeviceHeaterGround : public Device
{
public:
	DeviceHeaterGround(ReadRegisters *rr, WriteRegisters *wr, AlarmRegisters *ar, CommandRegisters *cr, Context context) :
		Device(rr, wr, ar, cr, context){};
	virtual void process();
	virtual ~DeviceHeaterGround() {};

protected:
	virtual void on() { Device::on(); };
	virtual void off();
	virtual void simulate_status();
};

class DeviceHeaterBackGround : public Device
{
public:
	DeviceHeaterBackGround(ReadRegisters *rr, WriteRegisters *wr, AlarmRegisters *ar, CommandRegisters *cr, Context context) :
		Device(rr, wr, ar, cr, context){};
	virtual void process();
	virtual ~DeviceHeaterBackGround() {};

protected:
	virtual void on() { Device::on(); };
	virtual void off();
	virtual void simulate_status();
};

class DevicePump : public Device
{
public:
	DevicePump(ReadRegisters *rr, WriteRegisters *wr, AlarmRegisters *ar, CommandRegisters *cr, Context context) :
		Device(rr, wr, ar, cr, context){};
	virtual void process() {};
	virtual ~DevicePump() {};

protected:
	virtual void on() {};
	virtual void off() {};
	virtual void simulate_status() {};
};

class DeviceRod : public Device
{
public:
	DeviceRod(ReadRegisters *rr, WriteRegisters *wr, AlarmRegisters *ar, CommandRegisters *cr, Context context) :
		Device(rr, wr, ar, cr, context){};
	virtual void process() {};
	virtual ~DeviceRod() {};

protected:
	virtual void on() {};
	virtual void off() {};
	virtual void simulate_status() {};
};

class DeviceCrucible : public Device
{
public:
	DeviceCrucible(ReadRegisters *rr, WriteRegisters *wr, AlarmRegisters *ar, CommandRegisters *cr, Context context) :
		Device(rr, wr, ar, cr, context){};
	virtual void process() {};
	virtual ~DeviceCrucible() {};

protected:
	virtual void on() {};
	virtual void off() {};
	virtual void simulate_status() {};
};

class DeviceMain : public Device
{
public:
	DeviceMain(ReadRegisters *rr, WriteRegisters *wr, AlarmRegisters *ar, CommandRegisters *cr, Context context) :
		Device(rr, wr, ar, cr, context){};
	virtual void process() {};
	virtual ~DeviceMain() {};

protected:
	virtual void on() {};
	virtual void off() {};
	virtual void simulate_status() {};
};