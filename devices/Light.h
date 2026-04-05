#ifndef LIGHT_H
#define LIGHT_H

#include "../state/LightState.h"
#include "IDevice.h"
#include <string>

using namespace std;

class Light
{
public:
    Light(const string &name);
    ~Light();

    void setState(LightState *s);
    void turnOn();
    void turnOff();
    void dim(int level);

    string getName() const;
    string status() const;

private:
    string name_;
    int brightness;
    LightState *state;
};

class LightDevice : public IDevice
{
public:
    LightDevice(const string &name);

    string getName() const override;
    void turnOn() override;
    void turnOff() override;
    string status() const override;

    void dim(int level);

private:
    Light *light;
};

#endif
