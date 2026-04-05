#include "TurnOffCommand.h"

TurnOffCommand::TurnOffCommand(IDevice *dev)
    : device(dev) {}

void TurnOffCommand::execute()
{
    device->turnOff();
}

void TurnOffCommand::undo()
{
    device->turnOn();
}
