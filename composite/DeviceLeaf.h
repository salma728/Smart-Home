#ifndef DEVICELEAF_H
#define DEVICELEAF_H

#include "../devices/IDevice.h"
#include "IComponent.h"
#include <memory>

using namespace std;

class DeviceLeaf : public IComponent
{
public:
    DeviceLeaf(unique_ptr<IDevice> dev);

    string getName() const override;
    void turnOn() override;
    void turnOff() override;
    string status() const override;

    IDevice *getRawDevice() const;

private:
    unique_ptr<IDevice> device;
};

#endif
