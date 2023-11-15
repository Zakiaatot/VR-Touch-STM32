#ifndef _MAIN_MCU_H_
#define _MAIN_MCU_H_

#include "Singleton.h"
class Rocker;
class Serial;

class MainMCU
{
    friend class Singleton<MainMCU>;

private:
    MainMCU();
    ~MainMCU();

public:
    void Setup() const;
    void Loop() const;

private:
    Rocker &rocker_;
    Serial &serial_;
};

#endif //_MAIN_MCU_H_
