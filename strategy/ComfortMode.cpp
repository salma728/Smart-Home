#include "ComfortMode.h"
#include <iostream>

using namespace std;

string ComfortMode::name() const
{
    return "Comfort Mode";
}

void ComfortMode::apply()
{
    cout << "[Automation] Applying Comfort Mode...\n";
}
