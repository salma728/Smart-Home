#include "LightState.h"
#include "../devices/Light.h"
#include <iostream>

using namespace std;

// ===== Global (shared) instances of each state =====
LightState *GLOBAL_LIGHT_ON = new LightOnState();
LightState *GLOBAL_LIGHT_OFF = new LightOffState();
LightState *GLOBAL_LIGHT_DIMMED = new LightDimmedState();

// ===== LightOnState =====
void LightOnState::turnOn(Light *light)
{
    cout << light->getName() << ": already ON\n";
}

void LightOnState::turnOff(Light *light)
{
    cout << light->getName() << ": turning OFF\n";
    light->setState(GLOBAL_LIGHT_OFF);
}

void LightOnState::dim(Light *light, int level)
{
    cout << light->getName() << ": dimming to " << level << "\n";
    light->setState(GLOBAL_LIGHT_DIMMED);
}

string LightOnState::name() const
{
    return "ON";
}

// ===== LightOffState =====
void LightOffState::turnOn(Light *light)
{
    cout << light->getName() << ": turning ON\n";
    light->setState(GLOBAL_LIGHT_ON);
}

void LightOffState::turnOff(Light *light)
{
    cout << light->getName() << ": already OFF\n";
}

void LightOffState::dim(Light *light, int level)
{
    cout << light->getName() << ": dimming from OFF to level " << level << "\n";
    light->setState(GLOBAL_LIGHT_DIMMED);
}

string LightOffState::name() const
{
    return "OFF";
}

// ===== LightDimmedState =====
void LightDimmedState::turnOn(Light *light)
{
    cout << light->getName() << ": restoring to full brightness\n";
    light->setState(GLOBAL_LIGHT_ON);
}

void LightDimmedState::turnOff(Light *light)
{
    cout << light->getName() << ": turning OFF from DIMMED\n";
    light->setState(GLOBAL_LIGHT_OFF);
}

void LightDimmedState::dim(Light *light, int level)
{
    cout << light->getName() << ": adjusting dim level to " << level << "\n";
    // Stay in dimmed state
}

string LightDimmedState::name() const
{
    return "DIMMED";
}
