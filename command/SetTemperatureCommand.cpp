#include "SetTemperatureCommand.h"

SetTemperatureCommand::SetTemperatureCommand(ThermostatDevice *dev, double temp)
    : device(dev), newTemperature(temp), previousTemperature(dev->temperature) {}

void SetTemperatureCommand::execute()
{
    previousTemperature = device->temperature;
    device->setTemperature(newTemperature);
}

void SetTemperatureCommand::undo()
{
    device->setTemperature(previousTemperature);
}
