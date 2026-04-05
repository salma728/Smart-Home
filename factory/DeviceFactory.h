#ifndef DEVICEFACTORY_H
#define DEVICEFACTORY_H

#include <memory>
#include <string>

using namespace std;

class LightDevice;
class ThermostatDevice;
class CameraDevice;
class DoorLockDevice;
class MotionSensor;

class DeviceFactory
{
public:
    virtual ~DeviceFactory() = default;

    virtual unique_ptr<LightDevice> createLight(const string &name) = 0;
    virtual unique_ptr<ThermostatDevice> createThermostat(const string &name) = 0;
    virtual unique_ptr<CameraDevice> createCamera(const string &name) = 0;
    virtual unique_ptr<DoorLockDevice> createDoorLock(const string &name) = 0;
    virtual unique_ptr<MotionSensor> createMotionSensor(const string &name) = 0;
};

#endif
