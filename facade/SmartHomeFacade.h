#ifndef SMARTHOMEFACADE_H
#define SMARTHOMEFACADE_H

#include "../factory/DeviceFactory.h"
#include "../composite/DeviceGroup.h"
#include "../composite/DeviceLeaf.h"
#include "../command/CommandManager.h"
#include "../command/TurnOnCommand.h"
#include "../command/TurnOffCommand.h"
#include "../command/SetTemperatureCommand.h"
#include "../strategy/AutomationContext.h"
#include "../strategy/EnergySavingMode.h"
#include "../strategy/ComfortMode.h"
#include "../observer/DeviceObserverAdapter.h"
#include "../devices/MotionSensor.h"
#include "../devices/Thermostat.h"

#include <map>
#include <memory>
#include <string>

using namespace std;

class SmartHomeFacade
{
public:
    SmartHomeFacade(unique_ptr<DeviceFactory> factory);

    // Device management
    void addLight(const string &name);
    void addThermostat(const string &name);
    void addCamera(const string &name);
    void addDoorLock(const string &name);
    void addMotionSensor(const string &name);

    // Group management
    void createGroup(const string &groupName);
    void addDeviceToGroup(const string &deviceName, const string &groupName);

    // Basic operations (individual devices)
    void turnOn(const string &deviceName);
    void turnOff(const string &deviceName);
    void setTemperature(const string &deviceName, double temp);
    
    // Group operations
    void turnOnGroup(const string &groupName);
    void turnOffGroup(const string &groupName);

    // Observer connections
    void connectMotionToDevice(const string &sensorName, const string &deviceName);

    // Automation
    void setModeEnergySaving();
    void setModeComfort();
    void applyMode();

    // Undo
    void undoLast();

    // System info
    void printGroupStatus(const string &groupName) const;
    IDevice *getDevice(const string &name) const;

private:
    unique_ptr<DeviceFactory> factory;
    CommandManager commandManager;
    AutomationContext automationContext;

    map<string, shared_ptr<IComponent>> components;
    map<string, shared_ptr<DeviceGroup>> groups;

    MotionSensor *getSensor(const string &name) const;
};

#endif
