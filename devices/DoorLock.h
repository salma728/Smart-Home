#ifndef DOORLOCK_H
#define DOORLOCK_H

#include "IDevice.h"
#include <string>

using namespace std;

class DoorLockDevice : public IDevice
{
public:
    DoorLockDevice(const string &name);

    string getName() const override;
    void turnOn() override;  // unlock
    void turnOff() override; // lock

    string status() const override;

private:
    string name;
    bool locked;
};

#endif
