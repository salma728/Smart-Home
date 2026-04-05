#include "DeviceObserverAdapter.h"
#include <iostream>

using namespace std;

DeviceObserverAdapter::DeviceObserverAdapter(IDevice *dev, const string &evt)
    : device(dev), reactEvent(evt) {}

void DeviceObserverAdapter::update(const string &event, ISubject *sender)
{
    if (event == reactEvent)
    {
        cout << "[Observer] " << device->getName()
             << " reacting to event: " << event << "\n";

        // Example reaction: turn device ON
        device->turnOn();
    }
}
