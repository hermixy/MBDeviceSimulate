#include "stdafx.h"
#include "WriteRegisters.h"


WriteRegisters::WriteRegisters()
{
	temp_heater_1 = temp_heater_2 = amperage_heater_1 = amperage_heater_2 = amperage_heater_3 = voltage_heater_1 = voltage_heater_2 =
		voltage_heater_3 = residual_pressure = inert_gas_pressure = rate_rod = rate_crucible = rate_rotational_rod =
		rate_rotational_crucible = shift_rod = shift_crucible = weight = 0.f;
}

void WriteRegisters::getAll(uint16_t *dest)
{
	copy_state(temp_heater_1, dest, 0, 1);
	copy_state(temp_heater_2, dest, 2, 3);
	copy_state(amperage_heater_1, dest, 4, 5);
	copy_state(amperage_heater_2, dest, 6, 7);
	copy_state(amperage_heater_3, dest, 8, 9);
	copy_state(voltage_heater_1, dest, 10, 11);
	copy_state(voltage_heater_2, dest, 12, 13);
	copy_state(voltage_heater_3, dest, 14, 15);
	copy_state(residual_pressure, dest, 16, 17);
	copy_state(inert_gas_pressure, dest, 18, 19);
	copy_state(rate_rod, dest, 20, 21);
	copy_state(rate_crucible, dest, 22, 23);
	copy_state(rate_rotational_rod, dest, 24, 25);
	copy_state(rate_rotational_crucible, dest, 26, 27);
	copy_state(shift_rod, dest, 28, 29);
	copy_state(shift_crucible, dest, 30, 31);
	copy_state(weight, dest, 32, 33);
}

void WriteRegisters::set_temp_heater_1(float temp_heater_1)
{
	this->temp_heater_1 = temp_heater_1;
}

void WriteRegisters::set_temp_heater_2(float temp_heater_2)
{
	this->temp_heater_2 = temp_heater_2;
}

void WriteRegisters::set_amperage_heater_1(float amperage_heater_1)
{
	this->amperage_heater_1 = amperage_heater_1;
}

void WriteRegisters::set_amperage_heater_2(float amperage_heater_2)
{
	this->amperage_heater_2 = amperage_heater_2;
}

void WriteRegisters::set_amperage_heater_3(float amperage_heater_3)
{
	this->amperage_heater_3 = amperage_heater_3;
}

void WriteRegisters::set_voltage_heater_1(float voltage_heater_1)
{
	this->voltage_heater_1 = voltage_heater_1;
}

void WriteRegisters::set_voltage_heater_2(float voltage_heater_2)
{
	this->voltage_heater_2 = voltage_heater_2;
}

void WriteRegisters::set_voltage_heater_3(float voltage_heater_3)
{
	this->voltage_heater_3 = voltage_heater_3;
}

void WriteRegisters::set_residual_pressure(float residual_pressure)
{
	this->residual_pressure = residual_pressure;
}

void WriteRegisters::set_inert_gas_pressure(float inert_gas_pressure)
{
	this->inert_gas_pressure = inert_gas_pressure;
}

void WriteRegisters::set_rate_rod(float rate_rod)
{
	this->rate_rod = rate_rod;
}

void WriteRegisters::set_rate_crucible(float rate_crucible)
{
	this->rate_crucible = rate_crucible;
}

void WriteRegisters::set_rate_rotational_rod(float rate_rotational_rod)
{
	this->rate_rotational_rod = rate_rotational_rod;
}

void WriteRegisters::set_rate_rotational_crucible(float rate_rotational_crucible)
{
	this->rate_rotational_crucible = rate_rotational_crucible;
}

void WriteRegisters::set_shift_rod(float shift_rod)
{
	this->shift_rod = shift_rod;
}

void WriteRegisters::set_shift_crucible(float shift_crucible)
{
	this->shift_crucible = shift_crucible;
}

void WriteRegisters::set_weight(float weight)
{
	this->weight = weight;
}

void  WriteRegisters::copy_state(float state, uint16_t *dest, int index_1, int index_2)
{
	uint16_t tmp[2];
	modbus_set_float(state, tmp);
	dest[index_1] = tmp[0];
	dest[index_2] = tmp[1];
}

WriteRegisters::~WriteRegisters()
{
}


