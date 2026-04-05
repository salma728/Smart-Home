#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "IDevice.h"
#include <string>

using namespace std;

class ThermostatDevice : public IDevice
{
public:
    ThermostatDevice(const string &name);

    string getName() const override;
    void turnOn() override;
    void turnOff() override;
    void setTemperature(double t);

    string status() const override;

    double temperature;

private:
    string name;
};

#endif
