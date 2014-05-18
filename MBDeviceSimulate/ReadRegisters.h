#pragma once

#include "modbus.h"

class ReadRegisters
{
public:
	ReadRegisters();
	void setAll(uint16_t *src);
	float get_temp_heater_1() { return temp_heater_1; };
	float get_temp_heater_2() { return temp_heater_2; };
	float get_temp_heater_3() { return temp_heater_3; };
	float get_rate_rod() { return rate_rod; };
	float get_rate_crucible() { return rate_crucible; };
	float get_rate_rotational_rod() { return rate_rotational_rod; };
	float get_rate_rotational_crucible() { return rate_rotational_crucible; };
	float get_pressure() { return pressure; };
	float get_delta_pressure() { return delta_pressure; };
	~ReadRegisters();

private:
	float get_float(uint16_t *src, int index_1, int index_2);

	float temp_heater_1;
	float temp_heater_2;
	float temp_heater_3;
	float rate_rod;  // скорость перемещения штока затравки
	float rate_crucible;  // скорость перемещения тигля
	float rate_rotational_rod;
	float rate_rotational_crucible;
	float pressure;
	float delta_pressure;
};

