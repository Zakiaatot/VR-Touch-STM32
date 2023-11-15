#ifndef _SERIAL_H_
#define _SERIAL_H_

#include <HardwareSerial.h>
#include "NoneCopyAble.h"
#include "Singleton.h"
#include "config.h"

class Serial : private HardwareSerial, private NoneCopyAble
{
    friend class Singleton<Serial>;

private:
    explicit Serial(const uint32_t rx, const uint32_t tx);
    ~Serial();

public:
    void Setup(uint32_t portRate = 9600);
    int RecvN(char *buf, size_t len);          // blocking
    size_t SendN(const char *buf, size_t len); // blocking
    void Flush();
    bool Available();
    // Endline empty class
    struct ENDL
    {
    } endl;

    // Overload the << operator
    Serial &operator<<(const char *str);
    Serial &operator<<(const String &str);
    Serial &operator<<(const ENDL &);
    Serial &operator<<(const uint32_t &num);
    Serial &operator<<(const uint16_t &num);

    // Overload the >> operator
    Serial &operator>>(uint16_t &num);
    Serial &operator>>(uint32_t &num);
};

// SERIAL SINGLETON
template <>
class Singleton<Serial>
{
public:
    static Serial &Instance()
    {
        static Serial instance(SERIAL_CONFIG::RX, SERIAL_CONFIG::TX);
        return instance;
    }
};

#endif //_SERIAL_H_
