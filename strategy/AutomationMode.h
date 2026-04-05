#ifndef AUTOMATIONMODE_H
#define AUTOMATIONMODE_H

#include <string>

using namespace std;

class AutomationMode
{
public:
    virtual ~AutomationMode() = default;

    virtual string name() const = 0;
    virtual void apply() = 0;
};

#endif
