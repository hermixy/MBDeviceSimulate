#include "stdafx.h"
#include "devices.h"

// DeviceHeaterMain
void DeviceHeaterMain::process()
{
	if (cr->get_t_main() == 0 || cr->get_t_heater_1() == 0) {
		off();

	} else if (cr->get_t_heater_1() == 1) {
		on();
		simulate_status();

		int u = U_HEATER_1_1 + (rand() % (int)(U_HEATER_1_2 - U_HEATER_1_1 + 1));
		float i = (float) (P_HEATER_1 / u);

		wr->set_temp_heater_1(rr->get_temp_heater_1());
		wr->set_amperage_heater_1(i);
		wr->set_voltage_heater_1((float) u);

	}
		
}

void DeviceHeaterMain::off()
{
	Device::off();
	ar->set_power_heater_1(0);
	wr->set_temp_heater_1(0.f);
	wr->set_amperage_heater_1(0.f);
	wr->set_voltage_heater_1(0.f);
}

void DeviceHeaterMain::simulate_status()
{
	if (context.type == CONSTANT)
		ar->set_power_heater_1(context.status);
	else if (context.type == TOGGLE)
		ar->set_power_heater_1((ar->get_power_heater_1() == 0) ? 1 : 0);
	else
		ar->set_power_heater_1(rand() % 2);
}


// DeviceHeaterGround
void DeviceHeaterGround::process()
{
	if (cr->get_t_main() == 0 || cr->get_t_heater_2() == 0) {
		off();

	}
	else if (cr->get_t_heater_2() == 1) {
		on();
		simulate_status();

		int u = U_HEATER_2_1 + (rand() % (int)(U_HEATER_2_2 - U_HEATER_2_1 + 1));
		float i = (float)(P_HEATER_2 / u);

		wr->set_temp_heater_2(rr->get_temp_heater_2());
		wr->set_amperage_heater_2(i);
		wr->set_voltage_heater_2((float)u);

	}

}

void DeviceHeaterGround::off()
{
	Device::off();
	ar->set_power_heater_2(0);
	wr->set_temp_heater_2(0.f);
	wr->set_amperage_heater_2(0.f);
	wr->set_voltage_heater_2(0.f);
}

void DeviceHeaterGround::simulate_status()
{
	if (context.type == CONSTANT)
		ar->set_power_heater_2(context.status);
	else if (context.type == TOGGLE)
		ar->set_power_heater_2((ar->get_power_heater_2() == 0) ? 1 : 0);
	else
		ar->set_power_heater_2(rand() % 2);
}


// DeviceHeaterBackGround
void DeviceHeaterBackGround::process()
{
	if (cr->get_t_main() == 0 || cr->get_t_heater_3() == 0) {
		off();

	}
	else if (cr->get_t_heater_3() == 1) {
		on();
		simulate_status();

		int u = U_HEATER_3_1 + (rand() % (int)(U_HEATER_3_2 - U_HEATER_3_1 + 1));
		float i = (float)(P_HEATER_3 / u);

		wr->set_amperage_heater_3(i);
		wr->set_voltage_heater_3((float)u);

	}

}

void DeviceHeaterBackGround::off()
{
	Device::off();
	ar->set_power_heater_3(0);
	wr->set_amperage_heater_3(0.f);
	wr->set_voltage_heater_3(0.f);
}

void DeviceHeaterBackGround::simulate_status()
{
	if (context.type == CONSTANT)
		ar->set_power_heater_3(context.status);
	else if (context.type == TOGGLE)
		ar->set_power_heater_3((ar->get_power_heater_3() == 0) ? 1 : 0);
	else
		ar->set_power_heater_3(rand() % 2);
}