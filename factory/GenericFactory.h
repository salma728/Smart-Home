#ifndef GENERICFACTORY_H
#define GENERICFACTORY_H

#include "DeviceFactory.h"
#include <memory>
#include <string>

using namespace std;

class GenericFactory : public DeviceFactory
{
public:
    unique_ptr<LightDevice> createLight(const string &name) override;
    unique_ptr<ThermostatDevice> createThermostat(const string &name) override;
    unique_ptr<CameraDevice> createCamera(const string &name) override;
    unique_ptr<DoorLockDevice> createDoorLock(const string &name) override;
    unique_ptr<MotionSensor> createMotionSensor(const string &name) override;
};

#endif
