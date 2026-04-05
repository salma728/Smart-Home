#include "CommandManager.h"

using namespace std;

void CommandManager::executeCommand(unique_ptr<Command> cmd)
{
    cmd->execute();
    history.push(move(cmd));
}

void CommandManager::undoLast()
{
    if (!history.empty())
    {
        history.top()->undo();
        history.pop();
    }
}
