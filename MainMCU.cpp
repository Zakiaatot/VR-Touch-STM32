#include "MainMCU.h"
#include "Rocker.h"
#include "Serial.h"
#include "Package.h"
#include "Stream.h"

MainMCU::MainMCU()
    : rocker_(Singleton<Rocker>::Instance()),
      serial_(Singleton<Serial>::Instance())
{
}

MainMCU::~MainMCU()
{
}

void MainMCU::Setup() const
{
    serial_.Setup();
}

void MainMCU::Loop() const
{
    // report rocker status if changed
    if (rocker_.Update())
    {
        OutStream os;
        os << CMD_REPORT_ROCKER;
        os.Skip(sizeof(PackageHead::len));
        os << rocker_;
        os.RePosition(sizeof(PackageHead::cmd));
        uint16_t len = os.Len() - sizeof(PackageHead);
        os << len;
        // SERIAL.SendN(os.Data(), os.Len());

        InStream is(os.Data());
        uint16_t cmd;
        uint32_t x, y;
        is >> cmd >> len >> x >> y;

        // serial_ << "CMD: " << cmd << ", LEN: " << len << serial_.endl;
        // serial_ << "ROCKER: " << x << "," << y << serial_.endl;
    }

    // receive motor change
    if (serial_.Available())
    {
    }

    delay(100);
}