#ifndef ENERGYSAVINGMODE_H
#define ENERGYSAVINGMODE_H

#include "AutomationMode.h"

class EnergySavingMode : public AutomationMode
{
public:
    std::string name() const override;
    void apply() override;
};

#endif
