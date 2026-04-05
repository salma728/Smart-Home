#include "TurnOnCommand.h"

TurnOnCommand::TurnOnCommand(IDevice *dev)
    : device(dev) {}

void TurnOnCommand::execute()
{
    device->turnOn();
}

void TurnOnCommand::undo()
{
    device->turnOff();
}
