#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <Arduino.h>

namespace DEBUGGER_CONFIG
{
    const uint32_t BAUD_RATE = 9600;
    const uint32_t RX = PA10;
    const uint32_t TX = PA9;
}

namespace SERIAL_CONFIG
{
    const uint32_t BAUD_RATE = 115200;
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
    const uint32_t MOTOR_NUM = 5;
    const uint32_t MOTOR_HALF_ROUND_TIME = 870;
    const uint32_t MOTOR_HALF_ROUND_TIME_MAX = 1200;
    const uint32_t MOTOR_PIN[MOTOR_NUM][2] =
        {
            {PA6, PA5},
            {PC5, PC4},
            {PD9, PD8},
            {PD11, PD10},
            {PD13, PD12},
    };

}

#endif //_CONFIG_H_
