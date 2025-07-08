#include <iostream>
#include <string>
#include "calculate_trips.h"
#include "log_message.h"
#include "refill_energy.h"
#include "input_validator.h"
#include "energy_display.h"
#include "log_loading.h"

using namespace std;

// Constants
const int MAX_BATTERY = 100;
const int MAX_FUEL = 100;
const int MIN_BATTERY = 25;
const int MIN_FUEL = 25;
const int TRIP_BATTERY_COST = 5;
const int TRIP_FUEL_COST = 7;

// System check
void check_system(int battery, int fuel) {
    if (battery < MIN_BATTERY) {
        log_message(WARNING, "Battery level is too low!");
    }
    if (fuel < MIN_FUEL) {
        log_message(WARNING, "Fuel level is too low!");
    }
}

// Main program
int main() {
    log_message(DISPLAY, "Welcome to [ROBO-X]'s Interface.");
    log_message(DISPLAY, "[ROBO-X] needs " + to_string(TRIP_BATTERY_COST) + "% of battery and " +
                     to_string(TRIP_FUEL_COST) + " tons of fuel for each trip.");

    int battery = get_valid_input("Input battery [in %] (0 - 100%)", 0, MAX_BATTERY, "Battery");
    int fuel = get_valid_input("Input fuel [in tons] (0 - 100 tons)", 0, MAX_FUEL, "Fuel");

    if (battery == MAX_BATTERY && fuel == MAX_FUEL) {
        log_message(LOG, "Battery and fuel are full!\n");
    } else if (battery == MAX_BATTERY) {
        log_message(LOG, "Battery is full!\n");
    } else if (fuel == MAX_FUEL) {
        log_message(LOG, "Fuel is full!\n");
    }

    if (battery < MIN_BATTERY || fuel < MIN_FUEL) {
        log_message(WARNING, "[ROBO-X] is not ready to take off!");
        log_message(LOG, "Running System Check.");
        log_loading("Loading");
        check_system(battery, fuel);
        return 0;
    }

    energy_display(battery, fuel, MAX_BATTERY, MAX_FUEL);

    calculate_trips(battery, fuel, TRIP_FUEL_COST, TRIP_BATTERY_COST);

    char again;
    log_message(DISPLAY, "Would you like to make another trip? (y/n)");
    cout << ">> ";
    cin >> again;

    while ('y' == again || 'Y' == again) {

        do {
            if (fuel < TRIP_FUEL_COST) {
            log_message(WARNING, "Fuel not enough to make the trip!");
            refill_energy(battery, fuel, MAX_BATTERY, MAX_FUEL);

            energy_display(battery, fuel, MAX_BATTERY, MAX_FUEL);

            calculate_trips(battery, fuel, TRIP_FUEL_COST, TRIP_BATTERY_COST);

            log_message(DISPLAY, "Would you like to make another trip? (y/n)");
            cout << ">> ";
            cin >> again;
        }

        if (battery < TRIP_BATTERY_COST || battery % TRIP_BATTERY_COST != 0) {
            log_message(WARNING, "Battery not enough to make the trip!");
            refill_energy(battery, fuel, MAX_BATTERY, MAX_FUEL);

            energy_display(battery, fuel, MAX_BATTERY, MAX_FUEL);

            calculate_trips(battery, fuel, TRIP_FUEL_COST, TRIP_BATTERY_COST);

            log_message(DISPLAY, "Would you like to make another trip? (y/n)");
            cout << ">> ";
            cin >> again;
            }
        } while (fuel < TRIP_FUEL_COST || battery < TRIP_BATTERY_COST);

        calculate_trips(battery, fuel, TRIP_FUEL_COST, TRIP_BATTERY_COST);

        log_message(DISPLAY, "Would you like to make another trip? (y/n)");
        cout << ">> ";
        cin >> again;

    }

    if ('n' == again) {
        log_loading("Powering off engine");
        log_message(LOG, "Engine powered off.");
    }

    return 0;
}
