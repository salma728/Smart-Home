#include "DeviceGroup.h"
#include <iostream>
#include <algorithm>

using namespace std;

DeviceGroup::DeviceGroup(const string &n)
    : name(n) {}

void DeviceGroup::add(shared_ptr<IComponent> component)
{
    children.push_back(component);
}

void DeviceGroup::remove(const string &compName)
{
    children.erase(
        remove_if(
            children.begin(),
            children.end(),
            [&](const shared_ptr<IComponent> &c)
            {
                return c->getName() == compName;
            }),
        children.end());
}

string DeviceGroup::getName() const
{
    return name;
}

void DeviceGroup::turnOn()
{
    for (auto &c : children)
        c->turnOn();
}

void DeviceGroup::turnOff()
{
    for (auto &c : children)
        c->turnOff();
}

string DeviceGroup::status() const
{
    string result = "Group[" + name + "]:\n";
    for (auto &c : children)
        result += "  - " + c->status() + "\n";
    return result;
}
