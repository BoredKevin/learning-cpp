#include "trip_loop.h"
#include <iostream>
#include "calculate_trips.h"

using namespace std;

void trip_loop(int& fuel, int& battery)
{
    char again;
    log_message(DISPLAY, "Would you like to do another trip? (y/n)");
    cout << ">> ";
    cin >> again;

    while ('y' == again || 'Y' == again) {

            if (fuel < 7) {
                log_message(WARNING, "Fuel not enough to initiate a trip!")
            }

            if (battery < 5) {
                log_message(WARNING, "Battery not enough to initiate a trip!")
            }

            else {

            calculate_trips(fuel, battery, TRIP_FUEL_COST, TRIP_BATTERY_COST);

            log_message(DISPLAY, "Would you like to do another trip? (y/n)");
            cout << ">> ";
            cin >> again;
            }
    }
}

