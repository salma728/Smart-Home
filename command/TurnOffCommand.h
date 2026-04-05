#ifndef TURNOFFCOMMAND_H
#define TURNOFFCOMMAND_H

#include "Command.h"
#include "../devices/IDevice.h"

class TurnOffCommand : public Command
{
public:
    TurnOffCommand(IDevice *device);

    void execute() override;
    void undo() override;

private:
    IDevice *device;
};

#endif
