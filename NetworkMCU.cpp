#include "AT.h"
#include "NetworkMCU.h"
#include "Serial.h"
#include "Config.h"

NetworkMCU::NetworkMCU(Serial& serial)
    : serial_(serial)
{
}

NetworkMCU::~NetworkMCU()
{
}

void NetworkMCU::Setup()
{
    delay(2000);
    serial_ << AT::SET_STA_MODE << AT::ENDL;
    serial_.Flush();
    delay(1000);
    serial_ << AT::CONNECT_WIFI(NETWORK_CONFIG::WIFI_SSID, NETWORK_CONFIG::WIFI_PASSWORD)
        << AT::ENDL;
    serial_.Flush();
    delay(7000);
    serial_ << AT::CONNECT_TCP(NETWORK_CONFIG::SERVER_IP, NETWORK_CONFIG::SERVER_PORT)
        << AT::ENDL;
    serial_.Flush();
    delay(2000);
    serial_ << AT::SET_TRANSPARENT_MODE << AT::ENDL;
    delay(2000);
    serial_ << AT::BEGIN_TRANSPARENT_MODE << AT::ENDL;
    delay(1000);
    // clear serial
    serial_.ClearRecvBuf();
}

void NetworkMCU::Loop()
{
}