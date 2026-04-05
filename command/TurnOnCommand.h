#ifndef TURNONCOMMAND_H
#define TURNONCOMMAND_H

#include "Command.h"
#include "../devices/IDevice.h"

class TurnOnCommand : public Command
{
public:
    TurnOnCommand(IDevice *device);

    void execute() override;
    void undo() override;

private:
    IDevice *device; // not owned
};

#endif
