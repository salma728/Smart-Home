#include "MotionSensor.h"
#include <iostream>
#include <algorithm>

using namespace std;

MotionSensor::MotionSensor(const string &n)
    : name(n) {}

string MotionSensor::getName() const
{
    return name;
}

void MotionSensor::turnOn()
{
    cout << name << ": sensor ON\n";
}

void MotionSensor::turnOff()
{
    cout << name << ": sensor OFF\n";
}

string MotionSensor::status() const
{
    return "MotionSensor[" + name + "] observers=" + to_string(observers.size());
}

void MotionSensor::detectMotion()
{
    cout << name << ": motion detected\n";
    notify("motion_detected");
}

void MotionSensor::attach(IObserver *o)
{
    observers.push_back(o);
}

void MotionSensor::detach(IObserver *o)
{
    observers.erase(remove(observers.begin(), observers.end(), o), observers.end());
}

void MotionSensor::notify(const string &event)
{
    for (auto *o : observers)
        o->update(event, this);
}
