#include "Thermostat.h"
#include <iostream>

using namespace std;

ThermostatDevice::ThermostatDevice(const string &n)
    : name(n), temperature(22.0) {}

string ThermostatDevice::getName() const
{
    return name;
}

void ThermostatDevice::turnOn()
{
    cout << name << ": thermostat ON\n";
}

void ThermostatDevice::turnOff()
{
    cout << name << ": thermostat OFF\n";
}

void ThermostatDevice::setTemperature(double t)
{
    temperature = t;
    cout << name << ": set temperature to " << temperature << "\n";
}

string ThermostatDevice::status() const
{
    return "Thermostat[" + name + "] temp=" + to_string(temperature);
}
