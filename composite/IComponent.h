#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include <string>

using namespace std;

class IComponent
{
public:
    virtual ~IComponent() = default;

    virtual string getName() const = 0;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual string status() const = 0;
};

#endif
