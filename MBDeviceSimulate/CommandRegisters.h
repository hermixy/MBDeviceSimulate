#pragma once

#include "modbus.h"

class CommandRegisters
{
public:
	CommandRegisters();
	void setAll(uint16_t *commands);
	uint16_t get_t_main();
	uint16_t get_t_heater_1();
	uint16_t get_t_heater_2();
	uint16_t get_t_heater_3();
	uint16_t get_t_cooling_water();
	uint16_t get_t_bilge_pump();
	uint16_t get_t_movement_rod();
	uint16_t get_t_movement_crucible();
	uint16_t get_t_rotation_rod();
	uint16_t get_t_rotation_crucible();
	~CommandRegisters();

private:
	uint16_t t_main;
	uint16_t t_heater_1; 
	uint16_t t_heater_2;
	uint16_t t_heater_3;
	uint16_t t_cooling_water;
	uint16_t t_bilge_pump;
	uint16_t t_movement_rod;
	uint16_t t_movement_crucible;
	uint16_t t_rotation_rod;
	uint16_t t_rotation_crucible;
};

