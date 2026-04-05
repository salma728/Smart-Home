#ifndef CAMERA_H
#define CAMERA_H

#include "IDevice.h"
#include <string>

using namespace std;

class CameraDevice : public IDevice
{
public:
    CameraDevice(const string &name);

    string getName() const override;
    void turnOn() override;
    void turnOff() override;

    void enableNightVision();
    string status() const override;

private:
    string name;
    bool recording;
};

#endif
