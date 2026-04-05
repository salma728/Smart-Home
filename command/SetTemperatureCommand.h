#ifndef SETTEMPERATURECOMMAND_H
#define SETTEMPERATURECOMMAND_H

#include "Command.h"
#include "../devices/Thermostat.h"

class SetTemperatureCommand : public Command
{
public:
    SetTemperatureCommand(ThermostatDevice *device, double newTemp);

    void execute() override;
    void undo() override;

private:
    ThermostatDevice *device;
    double newTemperature;
    double previousTemperature;
};

#endif
