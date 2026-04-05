#ifndef DEVICEGROUP_H
#define DEVICEGROUP_H

#include "IComponent.h"
#include <vector>
#include <string>
#include <memory>

using namespace std;

class DeviceGroup : public IComponent
{
public:
    DeviceGroup(const string &name);

    void add(shared_ptr<IComponent> component);
    void remove(const string &name);

    string getName() const override;
    void turnOn() override;
    void turnOff() override;
    string status() const override;

private:
    string name;
    vector<shared_ptr<IComponent>> children;
};

#endif
