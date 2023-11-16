#ifndef _NETWORK_MCU_H_
#define _NETWORK_MCU_H_

#include "Singleton.h"
#include "MCU.h"

class Serial;

class NetworkMCU : public MCU
{
    friend class Singleton<NetworkMCU>;

private:
    explicit NetworkMCU(Serial &serial);
    ~NetworkMCU();

public:
    void Setup();
    void Loop();

private:
    Serial &serial_;
};

template <>
class Singleton<NetworkMCU>
{
public:
    static NetworkMCU &Instance(Serial &serial_)
    {
        static NetworkMCU instance(serial_);
        return instance;
    }
};

#endif //_NETWORK_MCU_H_
