#include <iostream>
#include <string>
#include "calculate_trips.h"
#include "log_message.h"
#include "log_loading.h"

using namespace std;

void calculate_trips(int& battery, int& fuel, int TRIP_FUEL_COST, int TRIP_BATTERY_COST)
{
    int max_trips_fuel = fuel / TRIP_FUEL_COST;
    int max_trips_battery = battery / TRIP_BATTERY_COST;
    int trip_limit = min(max_trips_fuel, max_trips_battery);
    int trips;

    do
    {

        log_message(DISPLAY, "Number of trips possible: " + to_string(min(fuel / TRIP_FUEL_COST, battery / TRIP_BATTERY_COST)));
        log_message(INPUT, "How many trips do you want to make?");
        cout << ">> ";
        cin >> trips;

        if (trips < 1)
        {
            log_message(WARNING, "Amount of trips cannot be zero or negative!\n");
        }
        else if (trips > trip_limit)
        {
            log_message(WARNING, "Energy isn't enough for that many trips!\n");
        }
    }
    while (trips < 0 || trips > trip_limit);

    // Perform trip
    int used_fuel = trips * TRIP_FUEL_COST;
    int used_battery = trips * TRIP_BATTERY_COST;

    log_message(LOG, "You are going to make " + to_string(trips) + " trips.");
    log_loading("Starting engine");
    log_message(LOG, "Successfully started engine.\n");
    log_loading("Initiating journey");
    log_message(LOG, "Journey successful.");
    log_message(LOG, "You have spent " + to_string(used_fuel) + " tons of fuel and " +
                to_string(used_battery) + "% of battery.\n");
    log_message(LOG, "You have " + to_string(fuel - used_fuel) + " tons of fuel and " +
                to_string(battery - used_battery) + "% of battery remaining.");

    fuel -= used_fuel;
    battery -= used_battery;
}
