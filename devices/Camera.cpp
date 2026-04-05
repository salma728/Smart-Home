#include "Camera.h"
#include <iostream>

using namespace std;

CameraDevice::CameraDevice(const string &n)
    : name(n), recording(false) {}

string CameraDevice::getName() const
{
    return name;
}

void CameraDevice::turnOn()
{
    recording = true;
    cout << name << ": recording started\n";
}

void CameraDevice::turnOff()
{
    recording = false;
    cout << name << ": recording stopped\n";
}

void CameraDevice::enableNightVision()
{
    cout << name << ": night vision enabled\n";
}

string CameraDevice::status() const
{
    return "Camera[" + name + "] recording=" + (recording ? "yes" : "no");
}
