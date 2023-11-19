#include "MotorManager.h"

MotorManager::MotorManager()
{
    motorArrPtr_ = new Motor * [MOTOR_CONFIG::MOTOR_NUM];
    for (int i = 0; i < MOTOR_CONFIG::MOTOR_NUM; i++)
        motorArrPtr_[i] = new Motor(MOTOR_CONFIG::MOTOR_PIN[i][0], MOTOR_CONFIG::MOTOR_PIN[i][1]);
}

MotorManager::~MotorManager()
{
    for (int i = 0; i < MOTOR_CONFIG::MOTOR_NUM; i++)
        delete motorArrPtr_[i];
    delete[] motorArrPtr_;
}

void MotorManager::Setup()
{
    for (int i = 0; i < MOTOR_CONFIG::MOTOR_NUM; i++)
        motorArrPtr_[i]->Setup();
}

void MotorManager::Loop()
{
    for (int i = 0; i < MOTOR_CONFIG::MOTOR_NUM; i++)
        motorArrPtr_[i]->Loop();
}
