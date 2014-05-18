#include "stdafx.h"
#include "CommandRegisters.h"


CommandRegisters::CommandRegisters()
{
	t_main = t_heater_1 = t_heater_2 = t_heater_3 = t_cooling_water = t_bilge_pump = t_movement_rod = t_movement_crucible =
		t_rotation_rod = t_rotation_crucible = 0;
}

void CommandRegisters::setAll(uint16_t *commands)
{
	t_main = commands[0];
	t_heater_1 = commands[1];
	t_heater_2 = commands[2];
	t_heater_3 = commands[3];
	t_cooling_water = commands[4];
	t_bilge_pump = commands[5];
	t_movement_rod = commands[6];
	t_movement_crucible = commands[7];
	t_rotation_rod = commands[8];
	t_rotation_crucible = commands[9];
}

uint16_t CommandRegisters::get_t_main()
{
	return t_main;
}

uint16_t CommandRegisters::get_t_heater_1()
{
	return t_heater_1;
}

uint16_t CommandRegisters::get_t_heater_2()
{
	return t_heater_2;
}

uint16_t CommandRegisters::get_t_heater_3()
{
	return t_heater_3;
}

uint16_t CommandRegisters::get_t_cooling_water()
{
	return t_cooling_water;
}

uint16_t CommandRegisters::get_t_bilge_pump()
{
	return t_bilge_pump;
}

uint16_t CommandRegisters::get_t_movement_rod()
{
	return t_movement_rod;
}

uint16_t CommandRegisters::get_t_movement_crucible()
{
	return t_movement_crucible;
}

uint16_t CommandRegisters::get_t_rotation_rod()
{
	return t_rotation_rod;
}

uint16_t CommandRegisters::get_t_rotation_crucible()
{
	return t_rotation_crucible;
}

CommandRegisters::~CommandRegisters()
{
}
