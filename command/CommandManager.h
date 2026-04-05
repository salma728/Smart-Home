#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include "Command.h"
#include <stack>
#include <memory>

using namespace std;

class CommandManager
{
public:
    void executeCommand(unique_ptr<Command> cmd);
    void undoLast();

private:
    stack<unique_ptr<Command>> history;
};

#endif
