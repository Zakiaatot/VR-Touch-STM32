#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <Arduino.h>

namespace DEBUGGER_CONFIG
{
    const uint32_t PORT_RATE = 9600;
    const uint32_t RX = PA10;
    const uint32_t TX = PA9;
}

namespace SERIAL_CONFIG
{
    const uint32_t PORT_RATE = 9600;
    const uint32_t RX = PA10;
    const uint32_t TX = PA9;
}

namespace ROCKER_CONFIG
{
    const uint32_t VR_X = PA3;
    const uint32_t VR_Y = PA2;
}

namespace MOTOR_CONFIG
{
    const uint32_t MOTOR_1_IA = PA6;
    const uint32_t MOTOR_1_IB = PA5;
    const uint32_t MOTOR_2_IA = PC5;
    const uint32_t MOTOR_2_IB = PC4;
    const uint32_t MOTOR_3_IA = PD9;
    const uint32_t MOTOR_3_IB = PD8;
    const uint32_t MOTOR_4_IA = PD11;
    const uint32_t MOTOR_4_IB = PD10;
    const uint32_t MOTOR_5_IA = PD13;
    const uint32_t MOTOR_5_IB = PD12;
}

#endif //_CONFIG_H_
