#include "stdafx.h"
#include "ReadRegisters.h"


ReadRegisters::ReadRegisters()
{
	temp_heater_1 = temp_heater_2 = temp_heater_3 = rate_rod = rate_crucible = rate_rotational_rod = rate_rotational_crucible =
		pressure = delta_pressure = 0.f;
}

void ReadRegisters::setAll(uint16_t *src)
{
	temp_heater_1 = get_float(src, 0, 1);
	temp_heater_2 = get_float(src, 2, 3);
	temp_heater_3 = get_float(src, 4, 5);
	rate_rod = get_float(src, 6, 7);
	rate_crucible = get_float(src, 8, 9);
	rate_rotational_rod = get_float(src, 10, 11);
	rate_rotational_crucible = get_float(src, 12, 13);
	pressure = get_float(src, 14, 15);
	delta_pressure = get_float(src, 16, 17);
}


float ReadRegisters::get_float(uint16_t *src, int index_1, int index_2)
{
	uint16_t node[2];
	node[0] = src[index_1];
	node[2] = src[index_2];
	return modbus_get_float(node);
}

ReadRegisters::~ReadRegisters()
{
}
