#ifndef COMFORTMODE_H
#define COMFORTMODE_H

#include "AutomationMode.h"

using namespace std;

class ComfortMode : public AutomationMode
{
public:
    string name() const override;
    void apply() override;
};

#endif
