#include <Arduino.h>
#include "MainMCU.h"
#include "Config.h"
#include "AT.h"

MainMCU::MainMCU()
    : rocker_(ROCKER_CONFIG::VR_X, ROCKER_CONFIG::VR_Y),
      serial_(SERIAL_CONFIG::RX, SERIAL_CONFIG::TX),
      networkMCU_(Singleton<NetworkMCU>::Instance(serial_))
{
}

MainMCU::~MainMCU()
{
}

void MainMCU::Setup()
{
    serial_.Setup(SERIAL_CONFIG::BAUD_RATE);
}

void MainMCU::Loop()
{
    if (rocker_.Update())
    {
        // serial_ << rocker_ << serial_.endl;
    }

    if (serial_.Available())
    {
    }
    delay(1000);
}