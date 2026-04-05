#ifndef IDEVICE_H
#define IDEVICE_H

#include <string>
using namespace std;

class IDevice
{
public:
    virtual ~IDevice() = default;

    virtual string getName() const = 0;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual string status() const = 0;
};

#endif
