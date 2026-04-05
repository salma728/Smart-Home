#ifndef LIGHTSTATE_H
#define LIGHTSTATE_H

#include <string>

using namespace std;

class Light;

// ===== State Interface =====
class LightState
{
public:
    virtual ~LightState() = default;

    virtual void turnOn(Light *light) = 0;
    virtual void turnOff(Light *light) = 0;
    virtual void dim(Light *light, int level) = 0;

    virtual string name() const = 0;
};

// ===== Concrete States =====
class LightOnState : public LightState
{
public:
    void turnOn(Light *light) override;
    void turnOff(Light *light) override;
    void dim(Light *light, int level) override;
    string name() const override;
};

class LightOffState : public LightState
{
public:
    void turnOn(Light *light) override;
    void turnOff(Light *light) override;
    void dim(Light *light, int level) override;
    string name() const override;
};

class LightDimmedState : public LightState
{
public:
    void turnOn(Light *light) override;
    void turnOff(Light *light) override;
    void dim(Light *light, int level) override;
    string name() const override;
};

// Global shared instances (defined in LightState.cpp)
extern LightState *GLOBAL_LIGHT_ON;
extern LightState *GLOBAL_LIGHT_OFF;
extern LightState *GLOBAL_LIGHT_DIMMED;

#endif
