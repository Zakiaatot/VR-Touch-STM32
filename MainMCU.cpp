#include <Arduino.h>
#include "MainMCU.h"
#include "Config.h"
#include "AT.h"

MainMCU::MainMCU()
    : rocker_(ROCKER_CONFIG::VR_X, ROCKER_CONFIG::VR_Y),
    serial_(SERIAL_CONFIG::RX, SERIAL_CONFIG::TX),
    networkMCU_(Singleton<NetworkMCU>::Instance(serial_)),
    motorManager_(Singleton<MotorManager>::Instance())
{
}

MainMCU::~MainMCU()
{
}

void MainMCU::Setup()
{
    serial_.Setup(SERIAL_CONFIG::BAUD_RATE);
    networkMCU_.Setup();
    motorManager_.Setup();
}

void MainMCU::Loop()
{
    if (rocker_.Update())
    {
        Rocker::Status status = rocker_.GetYStatus();
        if (status == Rocker::Status::UP)
        {
            for (int i = 0; i < MOTOR_CONFIG::MOTOR_NUM; i++)
            {
                motorManager_.GetNthMotor(i)->Up();
            }
        }
        else if (status == Rocker::Status::DOWN)
        {
            for (int i = 0; i < MOTOR_CONFIG::MOTOR_NUM; i++)
            {
                motorManager_.GetNthMotor(i)->Down();
            }
        }
    }

    if (serial_.Available())
    {
        // serial
    }

    motorManager_.Loop();
}