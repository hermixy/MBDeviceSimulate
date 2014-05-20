// Constants.h
#if !defined(MODBUS_CONSTANTS_H)
#define MODBUS_CONSTANTS_H 1

const int P_HEATER_1 = 800;
const int P_HEATER_2 = 850;
const int P_HEATER_3 = 810;

const int U_HEATER_1_1 = 215;
const int U_HEATER_1_2 = 230;

const int U_HEATER_2_1 = 219;
const int U_HEATER_2_2 = 225;

const int U_HEATER_3_1 = 210;
const int U_HEATER_3_2 = 230;

const float MAX_TEMP_HEATER_1 = 1400.0f;
const float MAX_TEMP_HEATER_2 = 1200.0f;
const float MAX_TEMP_HEATER_3 = 1200.0f;

const float TEMP_2_U_DELTA_HEATER_1 = .2f;
const float TEMP_2_U_DELTA_HEATER_2 = .1f;
const float TEMP_2_U_DELTA_HEATER_3 = .1f;

#endif