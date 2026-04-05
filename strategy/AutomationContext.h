#ifndef AUTOMATIONCONTEXT_H
#define AUTOMATIONCONTEXT_H

#include "AutomationMode.h"
#include <memory>

using namespace std;

class AutomationContext
{
public:
    AutomationContext();

    void setMode(unique_ptr<AutomationMode> m);
    void applyMode();

    string currentModeName() const;

private:
    unique_ptr<AutomationMode> mode;
};

#endif
