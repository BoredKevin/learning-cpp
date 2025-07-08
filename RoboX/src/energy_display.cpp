#include "energy_display.h"
#include <string>
#include "log_message.h"
#include "log_loading.h"
#include <iostream>

using namespace std;

void energy_display(int& battery, int& fuel, int MAX_BATTERY, int MAX_FUEL)
{
    log_message(LOG, "Displaying battery and fuel levels.");
    log_loading("Loading");

    log_message(DISPLAY, "Battery level: " + to_string(battery) + "/" + to_string(MAX_BATTERY) + "%.");
    log_message(DISPLAY, "Fuel level: " + to_string(fuel) + "/" + to_string(MAX_FUEL) + " tons.\n");
}
