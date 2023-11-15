#ifndef _PACKAGE_H_
#define _PACKAGE_H_

#include <stdint.h>

#define CMD_REPORT_ROCKER (uint16_t)0x01
#define CMD_CHANGE_MOTOR (uint16_t)0x02

struct PackageHead
{
    uint16_t cmd;
    uint16_t len;
};

struct Package
{
    PackageHead head;
    char *body;
};

#endif //_PACKAGE_H_
