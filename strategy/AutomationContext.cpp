#include "AutomationContext.h"
#include "EnergySavingMode.h"

using namespace std;

AutomationContext::AutomationContext()
{
    // Default mode
    mode = make_unique<EnergySavingMode>();
}

void AutomationContext::setMode(unique_ptr<AutomationMode> m)
{
    mode = move(m);
}

void AutomationContext::applyMode()
{
    if (mode)
        mode->apply();
}

string AutomationContext::currentModeName() const
{
    if (mode)
        return mode->name();
    return "No Mode";
}
