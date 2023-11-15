#ifndef _ROCKER_H_
#define _ROCKER_H_

#include "NoneCopyAble.h"
#include "Singleton.h"
#include "config.h"

class Debugger;
class Serial;
class OutStream;

class Rocker : private NoneCopyAble
{
    friend class Singleton<Rocker>;

private:
    explicit Rocker(const uint32_t vrXPin, const uint32_t vrYPin);
    ~Rocker();

public:
    bool Update(); // return true if rocker is changed

    // rocker status
    enum Status
    {
        NONE = 0,
        UP = 1,
        DOWN = 2,
        LEFT = 3,
        RIGHT = 4,
        CENTER = 5
    };

    // debug
    friend Debugger &
    operator<<(Debugger &debugger, const Rocker &rocker);

    friend Serial &
    operator<<(Serial &serial, const Rocker &rocker);

    // trans
    friend OutStream &
    operator<<(OutStream &outStream, const Rocker &rocker);

private:
    const uint32_t vrXPin_;
    const uint32_t vrYPin_;
    uint32_t vrXDeg_;
    uint32_t vrYDeg_;
    Status xStatus_;
    Status yStatus_;
};

// ROCKER SINGLETON
template <>
class Singleton<Rocker>
{
public:
    static Rocker &Instance()
    {
        static Rocker instance(ROCKER_CONFIG::VR_X, ROCKER_CONFIG::VR_Y);
        return instance;
    }
};

#endif //_ROCKER_H_
