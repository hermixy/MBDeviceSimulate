#pragma once

#include "modbus.h"

class AlarmRegisters
{
public:
	AlarmRegisters();
	void getAll(uint16_t *dest);
	void set_power_main(uint16_t power_main) { this->power_main = power_main; };
	void set_power_heater_1(uint16_t power_heater_1) { this->power_heater_1 = power_heater_1; };
	void set_power_heater_2(uint16_t power_heater_2) { this->power_heater_2 = power_heater_2; };
	void set_power_heater_3(uint16_t power_heater_3) { this->power_heater_3 = power_heater_3; };
	void set_supply_water(uint16_t supply_water) { this->supply_water = supply_water; };
	void set_delta_pressure(uint16_t delta_pressure) { this->delta_pressure = delta_pressure; };
	void set_off_movement_rod(uint16_t off_movement_rod) { this->off_movement_rod = off_movement_rod; };
	void set_off_movement_crucible(uint16_t off_movement_crucible) { this->off_movement_crucible = off_movement_crucible; };
	void set_off_rotational_rod(uint16_t off_rotational_rod) { this->off_rotational_rod = off_rotational_rod; };
	void set_off_rotational_crucible(uint16_t off_rotational_crucible) { this->off_rotational_crucible = off_rotational_crucible; };
	void set_max_pos_rod(uint16_t max_pos_rod) { this->max_pos_rod = max_pos_rod; };
	void set_max_pos_crucible(uint16_t max_pos_crucible) { this->max_pos_crucible = max_pos_crucible; };
	void set_open_thermocouple(uint16_t open_thermocouple) { this->open_thermocouple = open_thermocouple; };

	uint16_t get_power_main() { return power_main; };
	uint16_t get_power_heater_1() { return power_heater_1; };
	uint16_t get_power_heater_2() { return power_heater_2; };
	uint16_t get_power_heater_3() { return power_heater_3; };
	uint16_t get_supply_water() { return supply_water; };
	uint16_t get_delta_pressure() { return delta_pressure; };
	uint16_t get_off_movement_rod() { return off_movement_rod; };
	uint16_t get_off_movement_crucible() { return off_movement_crucible; };
	uint16_t get_off_rotational_rod() { return off_rotational_rod; };
	uint16_t get_off_rotational_crucible() { return off_rotational_crucible; };
	uint16_t get_max_pos_rod() { return max_pos_rod; };
	uint16_t get_max_pos_crucible() { return max_pos_crucible; };
	uint16_t get_open_thermocouple() { return open_thermocouple; };

	~AlarmRegisters();

private:
	uint16_t power_main;
	uint16_t power_heater_1;
	uint16_t power_heater_2;
	uint16_t power_heater_3;
	uint16_t supply_water;
	uint16_t delta_pressure;
	uint16_t off_movement_rod;
	uint16_t off_movement_crucible;
	uint16_t off_rotational_rod;
	uint16_t off_rotational_crucible;
	uint16_t max_pos_rod;
	uint16_t max_pos_crucible;
	uint16_t open_thermocouple;
};
