#ifndef _MOTOR_H_
#define _MOTOR_H_

#include "Singleton.h"
#include "NoneCopyAble.h"

class Motor : NoneCopyAble
{
public:
    Motor(const uint32_t IA, const uint32_t IB);
    ~Motor();

    void Setup() const;
    void Forward();
    void Backward();

private:
    const uint32_t IA_;
    const uint32_t IB_;
};

#endif //_MOTOR_H_
