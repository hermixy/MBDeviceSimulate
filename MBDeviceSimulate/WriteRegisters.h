#pragma once

#include "modbus.h"

class WriteRegisters
{
public:
	WriteRegisters();
	void getAll(uint16_t *dest);
	void set_temp_heater_2(float temp_heater_2);
	void set_temp_heater_3(float temp_heater_3);
	void set_amperage_heater_1(float amperage_heater_1);
	void set_amperage_heater_2(float amperage_heater_2);
	void set_amperage_heater_3(float amperage_heater_3);
	void set_voltage_heater_1(float temp_heater_1);
	void set_voltage_heater_2(float temp_heater_2);
	void set_voltage_heater_3(float temp_heater_3);
	void set_residual_pressure(float residual_pressure);
	void set_inert_gas_pressure(float inert_gas_pressure);
	void set_rate_rod(float rate_rod);
	void set_rate_crucible(float rate_crucible);
	void set_rate_rotational_rod(float rate_rotational_rod);
	void set_rate_rotational_crucible(float rate_rotational_crucible);
	void set_shift_rod(float shift_rod);
	void set_shift_crucible(float shift_crucible);
	void set_weight(float weight);
	~WriteRegisters();
private:
	void copy_state(float state, uint16_t *dest, int index_1, int index_2);

	float temp_heater_2;
	float temp_heater_3;
	float amperage_heater_1;
	float amperage_heater_2;
	float amperage_heater_3;
	float voltage_heater_1;
	float voltage_heater_2;
	float voltage_heater_3;
	float residual_pressure;  // остаточное давление
	float inert_gas_pressure;
	float rate_rod;  // скорость перемещения штока затравки
	float rate_crucible;  // скорость перемещения тигля
	float rate_rotational_rod;
	float rate_rotational_crucible;
	float shift_rod;
	float shift_crucible;
	float weight;
};

