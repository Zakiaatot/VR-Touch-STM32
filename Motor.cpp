#include <Arduino.h>
#include "Motor.h"

Motor::Motor(const uint32_t IA, const uint32_t IB)
    : IA_(IA), IB_(IB)
{
}

Motor::~Motor()
{
}

void Motor::Setup() const
{
    pinMode(IA_, OUTPUT);
    pinMode(IB_, OUTPUT);
}

void Motor::Forward()
{
    analogWrite(IA_, 0);
    analogWrite(IB_, 255);
}

void Motor::Backward()
{
    analogWrite(IA_, 255);
    analogWrite(IB_, 0);
}
