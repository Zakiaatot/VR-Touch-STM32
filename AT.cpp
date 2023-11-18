#include <cstdio>
#include "AT.h"

const char *AT::ENDL = "\r\n";
const char *AT::SET_AP_MODE = "AT+CWMODE=1";

AutoPtrArray<const char> AT::CONNECT_WIFI(const char *ssid, const char *pwd)
{
    char *buf = new char[64]{0};
    sprintf(buf, "AT+CWJAP=\"%s\",\"%s\"", ssid, pwd);
    return AutoPtrArray<const char>(const_cast<const char *>(buf));
}

AutoPtrArray<const char> AT::CONNECT_TCP(const char *ip, uint16_t port)
{
    char *buf = new char[64]{0};
    sprintf(buf, "AT+CIPSTART=\"TCP\",\"%s\",%d", ip, port);
    return AutoPtrArray<const char>(const_cast<const char *>(buf));
}