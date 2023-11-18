#include "AT.h"
#include "NetworkMCU.h"
#include "Serial.h"
#include "Config.h"

NetworkMCU::NetworkMCU(Serial &serial)
    : serial_(serial)
{
}

NetworkMCU::~NetworkMCU()
{
}

void NetworkMCU::Setup()
{
    serial_ << AT::SET_AP_MODE << AT::ENDL;
    serial_.Flush();
    delay(1000);
    serial_ << AT::CONNECT_WIFI(NETWORK_CONFIG::WIFI_SSID, NETWORK_CONFIG::WIFI_PASSWORD)
            << AT::ENDL;
    serial_.Flush();
    delay(5000);
    serial_ << AT::CONNECT_TCP(NETWORK_CONFIG::SERVER_IP, NETWORK_CONFIG::SERVER_PORT)
            << AT::ENDL;
    serial_.Flush();
    delay(1000);
}

void NetworkMCU::Loop()
{
}