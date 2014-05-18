#include "stdafx.h"
#include "AlarmRegisters.h"


AlarmRegisters::AlarmRegisters()
{
	power_main = power_heater_1 = power_heater_2 = power_heater_3 = supply_water = delta_pressure =
		off_movement_rod = off_movement_crucible = off_rotational_rod = off_rotational_crucible =
		max_pos_rod = max_pos_crucible = open_thermocouple = 0;
}


void AlarmRegisters::getAll(uint16_t *dest)
{
	dest[0] = power_main;
	dest[1] = power_heater_1;
	dest[2] = power_heater_2;
	dest[3] = power_heater_3;
	dest[4] = supply_water;
	dest[5] = delta_pressure;
	dest[6] = off_movement_rod;
	dest[7] = off_movement_crucible;
	dest[8] = off_rotational_rod;
	dest[9] = off_rotational_crucible;
	dest[10] = max_pos_rod;
	dest[11] = max_pos_crucible;
	dest[12] = open_thermocouple;
}


AlarmRegisters::~AlarmRegisters()
{
}
