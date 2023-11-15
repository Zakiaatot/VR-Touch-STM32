#ifndef _STREAM_H_
#define _STREAM_H_

#include <stdint.h>
#include <cstring>
#include "AutoPtr.h"

class InStream
{
public:
    InStream(const char *const data = 0);
    ~InStream();

    void Reset(const char *const data = 0);
    void RePosition(uint16_t pos);

    InStream &operator>>(char *str);
    InStream &operator>>(uint16_t &num);
    InStream &operator>>(int &num);
    InStream &operator>>(uint32_t &num);

private:
    const char *data_;
    uint16_t dataPos_;
};

class OutStream
{
public:
    OutStream(uint32_t dSize = 128);
    ~OutStream();

    const char *const Data() const;
    uint16_t Len() const;

    void Append(const char *const str, size_t len);
    void Append(void *const data, size_t len);
    void WriteByte(const char *const data, size_t len);
    void WriteByte(void *const data, size_t len);
    void Skip(size_t len);
    void RePosition(size_t pos);
    void RePositionEnd();
    void clear();

    OutStream &operator<<(const char *const str);
    OutStream &operator<<(const uint8_t num);
    OutStream &operator<<(const uint16_t num);
    OutStream &operator<<(const int num);
    OutStream &operator<<(const uint32_t num);

private:
    AutoPtrArray<char> data_;
    uint16_t dataSize_;
    uint16_t dataPos_;
};

#endif //_STREAM_H_