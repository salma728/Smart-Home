#include "SmartHomeFacade.h"
#include <iostream>
#include "../devices/Light.h"
#include "../devices/Camera.h"
#include "../devices/DoorLock.h"

using namespace std;

SmartHomeFacade::SmartHomeFacade(unique_ptr<DeviceFactory> f)
    : factory(move(f)) {}

// ===== Device Creation =====

void SmartHomeFacade::addLight(const string &name)
{
    auto dev = factory->createLight(name);
    components[name] = make_shared<DeviceLeaf>(unique_ptr<IDevice>(dev.release()));
    cout << "[System] Added Light: " << name << "\n";
}

void SmartHomeFacade::addThermostat(const string &name)
{
    auto dev = factory->createThermostat(name);
    components[name] = make_shared<DeviceLeaf>(unique_ptr<IDevice>(dev.release()));
    cout << "[System] Added Thermostat: " << name << "\n";
}

void SmartHomeFacade::addCamera(const string &name)
{
    auto dev = factory->createCamera(name);
    components[name] = make_shared<DeviceLeaf>(unique_ptr<IDevice>(dev.release()));
    cout << "[System] Added Camera: " << name << "\n";
}

void SmartHomeFacade::addDoorLock(const string &name)
{
    auto dev = factory->createDoorLock(name);
    components[name] = make_shared<DeviceLeaf>(unique_ptr<IDevice>(dev.release()));
    cout << "[System] Added Door Lock: " << name << "\n";
}

void SmartHomeFacade::addMotionSensor(const string &name)
{
    auto dev = factory->createMotionSensor(name);
    components[name] = make_shared<DeviceLeaf>(unique_ptr<IDevice>(dev.release()));
    cout << "[System] Added Motion Sensor: " << name << "\n";
}

// ===== Groups =====

void SmartHomeFacade::createGroup(const string &groupName)
{
    groups[groupName] = make_shared<DeviceGroup>(groupName);
    cout << "[System] Created group: " << groupName << "\n";
}

void SmartHomeFacade::addDeviceToGroup(const string &deviceName, const string &groupName)
{
    if (components.count(deviceName) && groups.count(groupName))
    {
        groups[groupName]->add(components[deviceName]);
        cout << "[System] Added " << deviceName << " to group " << groupName << "\n";
    }
    else
    {
        cout << "[System] Error: Cannot add " << deviceName << " to " << groupName 
             << " (device or group not found)\n";
    }
}

// ===== Commands =====

void SmartHomeFacade::turnOn(const string &deviceName)
{
    if (auto dev = getDevice(deviceName))
    {
        commandManager.executeCommand(
            make_unique<TurnOnCommand>(dev));
    }
    else
    {
        cout << "[System] Error: Device '" << deviceName << "' not found\n";
    }
}

void SmartHomeFacade::turnOff(const string &deviceName)
{
    if (auto dev = getDevice(deviceName))
    {
        commandManager.executeCommand(
            make_unique<TurnOffCommand>(dev));
    }
    else
    {
        cout << "[System] Error: Device '" << deviceName << "' not found\n";
    }
}

void SmartHomeFacade::setTemperature(const string &deviceName, double temp)
{
    if (auto dev = dynamic_cast<ThermostatDevice *>(getDevice(deviceName)))
    {
        commandManager.executeCommand(
            make_unique<SetTemperatureCommand>(dev, temp));
    }
    else
    {
        cout << "[System] Error: Device '" << deviceName << "' is not a thermostat or not found\n";
    }
}

// ===== Group Operations =====

void SmartHomeFacade::turnOnGroup(const string &groupName)
{
    if (groups.count(groupName))
    {
        cout << "[System] Turning ON all devices in group: " << groupName << "\n";
        groups.at(groupName)->turnOn();
    }
    else
    {
        cout << "[System] Error: Group '" << groupName << "' not found\n";
    }
}

void SmartHomeFacade::turnOffGroup(const string &groupName)
{
    if (groups.count(groupName))
    {
        cout << "[System] Turning OFF all devices in group: " << groupName << "\n";
        groups.at(groupName)->turnOff();
    }
    else
    {
        cout << "[System] Error: Group '" << groupName << "' not found\n";
    }
}

// ===== Observer =====

void SmartHomeFacade::connectMotionToDevice(const string &sensorName, const string &deviceName)
{
    auto sensorComp = getSensor(sensorName);
    auto dev = getDevice(deviceName);

    if (sensorComp && dev)
    {
        auto adapter = new DeviceObserverAdapter(dev, "motion_detected");
        sensorComp->attach(adapter);
        cout << "[System] Connected " << sensorName << " to " << deviceName << "\n";
    }
    else
    {
        cout << "[System] Error: Cannot connect " << sensorName << " to " << deviceName 
             << " (sensor or device not found)\n";
    }
}

// ===== Automation =====

void SmartHomeFacade::setModeEnergySaving()
{
    automationContext.setMode(make_unique<EnergySavingMode>());
}

void SmartHomeFacade::setModeComfort()
{
    automationContext.setMode(make_unique<ComfortMode>());
}

void SmartHomeFacade::applyMode()
{
    automationContext.applyMode();
}

// ===== Undo =====

void SmartHomeFacade::undoLast()
{
    commandManager.undoLast();
    cout << "[System] Undo: Last command reversed\n";
}

// ===== Helpers =====

IDevice *SmartHomeFacade::getDevice(const string &name) const
{
    if (components.count(name))
    {
        auto leaf = dynamic_pointer_cast<DeviceLeaf>(components.at(name));
        if (leaf)
            return leaf->getRawDevice();
    }
    return nullptr;
}

MotionSensor *SmartHomeFacade::getSensor(const string &name) const
{
    auto dev = getDevice(name);
    return dynamic_cast<MotionSensor *>(dev);
}

// ===== Status =====

void SmartHomeFacade::printGroupStatus(const string &groupName) const
{
    if (groups.count(groupName))
    {
        cout << groups.at(groupName)->status();
    }
}
