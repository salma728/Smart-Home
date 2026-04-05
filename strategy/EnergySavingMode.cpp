#include "EnergySavingMode.h"
#include <iostream>

using namespace std;

string EnergySavingMode::name() const
{
    return "Energy Saving Mode";
}

void EnergySavingMode::apply()
{
    cout << "[Automation] Applying Energy Saving Mode...\n";
}
