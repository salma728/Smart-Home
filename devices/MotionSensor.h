#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

#include "IDevice.h"
#include "../observer/IObserver.h"
#include "../observer/ISubject.h"
#include <vector>
#include <string>

using namespace std;

class MotionSensor : public IDevice, public ISubject
{
public:
    MotionSensor(const string &name);

    string getName() const override;
    void turnOn() override;
    void turnOff() override;
    string status() const override;

    void detectMotion();

    // ISubject
    void attach(IObserver *o) override;
    void detach(IObserver *o) override;
    void notify(const string &event) override;

private:
    string name;
    vector<IObserver *> observers;
};

#endif
