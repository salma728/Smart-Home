#include "GenericFactory.h"

// include concrete device headers
#include "../devices/Light.h"
#include "../devices/Thermostat.h"
#include "../devices/Camera.h"
#include "../devices/DoorLock.h"
#include "../devices/MotionSensor.h"

#include <memory>

using namespace std;

unique_ptr<LightDevice> GenericFactory::createLight(const string &name)
{
    return make_unique<LightDevice>(name);
}

unique_ptr<ThermostatDevice> GenericFactory::createThermostat(const string &name)
{
    return make_unique<ThermostatDevice>(name);
}

unique_ptr<CameraDevice> GenericFactory::createCamera(const string &name)
{
    return make_unique<CameraDevice>(name);
}

unique_ptr<DoorLockDevice> GenericFactory::createDoorLock(const string &name)
{
    return make_unique<DoorLockDevice>(name);
}

unique_ptr<MotionSensor> GenericFactory::createMotionSensor(const string &name)
{
    return make_unique<MotionSensor>(name);
}
