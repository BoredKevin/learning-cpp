#include <iostream>
#include <string>
#include "calculate_trips.h"
#include "log_message.h"

using namespace std;

// Constants
const int MAX_BATTERY = 100;
const int MAX_FUEL = 100;
const int MIN_BATTERY = 25;
const int MIN_FUEL = 25;
const int TRIP_BATTERY_COST = 5;
const int TRIP_FUEL_COST = 7;

// Utility function
void log_loading(const string& message, int times = 3) {
    for (int i = 1; i <= times; ++i) {
        log_message(LOG, message + string(i, '.'));
    }
}

// System check
void check_system(int battery, int fuel) {
    if (battery < MIN_BATTERY) {
        log_message(WARNING, "Battery level is too low!");
    }
    if (fuel < MIN_FUEL) {
        log_message(WARNING, "Fuel level is too low!");
    }
}

// Input validator
int get_valid_input(const string& prompt, int min_value, int max_value, const string& unit) {
    int value;
    do {
        log_message(INPUT, prompt);
        cout << ">> ";
        cin >> value;

        if (value < min_value) {
            log_message(WARNING, unit + " cannot be less than " + to_string(min_value) + "!\n");
        } else if (value > max_value) {
            log_message(WARNING, unit + " cannot exceed " + to_string(max_value) + "!\n");
        }
    } while (value < min_value || value > max_value);

    return value;
}

// Main program
int main() {
    log_message(DISPLAY, "Welcome to [ROBO-X]'s Interface.");
    log_message(DISPLAY, "[ROBO-X] needs " + to_string(TRIP_BATTERY_COST) + "% of battery and " +
                     to_string(TRIP_FUEL_COST) + " tons of fuel for each trip.");

    int battery = get_valid_input("Input battery [in %] (0 - 100%)", 0, MAX_BATTERY, "Battery");
    int fuel = get_valid_input("Input fuel [in tons] (0 - 100 tons)", 0, MAX_FUEL, "Fuel");

    if (battery == MAX_BATTERY && fuel == MAX_FUEL) {
        log_message(LOG, "Battery and fuel are full!");
    } else if (battery == MAX_BATTERY) {
        log_message(LOG, "Battery is full!");
    } else if (fuel == MAX_FUEL) {
        log_message(LOG, "Fuel is full!");
    }

    if (battery < MIN_BATTERY || fuel < MIN_FUEL) {
        log_message(WARNING, "[ROBO-X] is not ready to take off!");
        log_message(LOG, "Running System Check.");
        log_loading("Loading");
        check_system(battery, fuel);
        return 0;
    }

    log_message(LOG, "[ROBO-X] is ready to take off!");
    log_message(LOG, "Displaying battery and fuel levels.");
    log_loading("Loading");

    log_message(DISPLAY, "Battery level: " + to_string(battery) + "%.");
    log_message(DISPLAY, "Fuel level: " + to_string(fuel) + " tons.");
    log_message(DISPLAY, "Number of trips possible: " +
                         to_string(min(fuel / TRIP_FUEL_COST, battery / TRIP_BATTERY_COST)));

    calculate_trips(fuel, battery, TRIP_FUEL_COST, TRIP_BATTERY_COST);

    char again;
    log_message(DISPLAY, "Would you like to do another trip? (y/n)");
    cout << ">> ";
    cin >> again;

    if ('y' == again || 'Y' == again) {
        calculate_trips(fuel, battery, TRIP_FUEL_COST, TRIP_BATTERY_COST);
    }

    return 0;
}
