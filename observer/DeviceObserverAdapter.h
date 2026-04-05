#ifndef DEVICEOBSERVERADAPTER_H
#define DEVICEOBSERVERADAPTER_H

#include "IObserver.h"
#include "../devices/IDevice.h"
#include <memory>

using namespace std;

class DeviceObserverAdapter : public IObserver
{
public:
    DeviceObserverAdapter(IDevice *device, const string &reactEvent);

    void update(const string &event, ISubject *sender) override;

private:
    IDevice *device;   // NOT owned
    string reactEvent; // event that triggers reaction
};

#endif
