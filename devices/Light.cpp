#include "Light.h"
#include "../state/LightState.h"
#include <iostream>

using namespace std;

// External global state instances
extern LightState *GLOBAL_LIGHT_ON;
extern LightState *GLOBAL_LIGHT_OFF;
extern LightState *GLOBAL_LIGHT_DIMMED;

// ===== Light class =====

Light::Light(const string &name)
    : name_(name), brightness(0), state(GLOBAL_LIGHT_OFF) {}

Light::~Light() {}

void Light::setState(LightState *s)
{
    state = s;
}

void Light::turnOn()
{
    state->turnOn(this);
}

void Light::turnOff()
{
    state->turnOff(this);
}

void Light::dim(int level)
{
    state->dim(this, level);
}

string Light::getName() const
{
    return name_;
}

string Light::status() const
{
    return "Light[" + name_ + "] brightness=" + to_string(brightness) +
           " state=" + state->name();
}

// ===== LightDevice (IDevice wrapper) =====

LightDevice::LightDevice(const string &name)
{
    light = new Light(name);
}

string LightDevice::getName() const
{
    return light->getName();
}

void LightDevice::turnOn()
{
    light->setState(GLOBAL_LIGHT_ON);
    light->turnOn();
}

void LightDevice::turnOff()
{
    light->setState(GLOBAL_LIGHT_OFF);
    light->turnOff();
}

string LightDevice::status() const
{
    return light->status();
}

void LightDevice::dim(int level)
{
    light->setState(GLOBAL_LIGHT_DIMMED);
    light->dim(level);
}
