#include "DoorLock.h"
#include <iostream>

using namespace std;

DoorLockDevice::DoorLockDevice(const string &n)
    : name(n), locked(true) {}

string DoorLockDevice::getName() const
{
    return name;
}

void DoorLockDevice::turnOn()
{
    locked = false;
    cout << name << ": unlocked\n";
}

void DoorLockDevice::turnOff()
{
    locked = true;
    cout << name << ": locked\n";
}

string DoorLockDevice::status() const
{
    return "DoorLock[" + name + "] locked=" + (locked ? "yes" : "no");
}
