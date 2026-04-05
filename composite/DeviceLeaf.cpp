#include "DeviceLeaf.h"

using namespace std;

DeviceLeaf::DeviceLeaf(unique_ptr<IDevice> dev)
    : device(move(dev)) {}

IDevice *DeviceLeaf::getRawDevice() const
{
    return device.get();
}

string DeviceLeaf::getName() const
{
    return device->getName();
}

void DeviceLeaf::turnOn()
{
    device->turnOn();
}

void DeviceLeaf::turnOff()
{
    device->turnOff();
}

string DeviceLeaf::status() const
{
    return device->status();
}
