# include <iostream>
# include <string>
using namespace std;

// SYSTEM CHECK
int check_system(int current_battery, int min_battery, int current_fuel, int min_fuel)
{
    if (current_battery < min_battery) (
        cout << "\n[ WARNING ] Battery level is too low!" << endl);
    if (current_fuel < min_fuel) (
        cout << "\n[ WARNING ] Fuel level is too low!" << endl);

    return 0;
}

// TRIPS CALCULATOR
int trips_calculator(int current_fuel, int current_battery, int trip_fuel, int trip_battery)
{
    int trips;

    // Fuel calculation for trips (1)
    int trip_fuel_check = current_fuel / trip_fuel;
    int trip_battery_check = current_battery / trip_battery;

    int trips_limit = min(trip_battery_check, trip_battery_check);


    // TRIPS CHECK
    do {
        cout << "\n[ LOG ] How many trips do you want to make? \n>> ";
        cin >> trips;
        if (trips > trips_limit) {
            cout << "[ WARNING ] Energy isn't enough for the trips!" << endl;
        }
        if (trips < 0) {
            cout << "[ WARNING ] Amount of trips cannot be negative!" << endl;
        }
    } while (trips > trips_limit || trips < 0);

        // Fuel calculation for trips (2)
        int used_fuel = trip_fuel * trips;
        int fuel_remainder = current_fuel - used_fuel;
        int used_battery = trip_battery * trips;
        int battery_remainder = current_battery - used_battery;

        if (trips_limit >= trips) {
            cout << "\n[ LOG ] You are going to make " << trips << " trips.\n" << endl;
            for (int i = 1; i <= 3; i++) {
                cout << "[ LOG ] Starting [ROBO-X]" << string(i, '.') << endl;
            }
            cout << "\n[ LOG ] Successfully starting engine." << endl;
            cout << "\n[ LOG ] Initiating trips...\n" << endl;
            for (int i = 1; i <= 3; i++) {
                cout << string(i, '.') << endl;
            }
            cout << "\n[ LOG ] Journey successful." << endl;
            cout << "[ LOG ] You have spent " << used_fuel << " tons of fuel and " << used_battery << "% of battery." << endl;
            cout << "[ LOG ] You have " << fuel_remainder << " tons of fuel and " << battery_remainder << "% of battery remaining." << endl;
        }

    return 0;
}

int main()
{
    // Admitting variables
    int current_battery;
    int min_battery = 25;
    int current_fuel;
    int min_fuel = 25;
    int trip_fuel = 7;
    int trip_battery = 5;

    // Welcome Log
    cout << "[ LOG ] Welcome to [ROBO - X]'s Interface.\n";
    cout << "[ LOG ] [ROBO-X] needs " << trip_battery << "% of battery and " << trip_fuel << " tons of fuel for each trip.\n\n";

    // User input & check (battery)
    do {
        cout << "[ LOG ] Input battery [in %] (Maximum = 100%)\n>> ";
        cin >> current_battery;

        if (current_battery < 0) {
            cout << "[ WARNING ] Battery level cannot be less than 1%!\n\n";
        }

        if (current_battery > 100) {
            cout << "[ WARNING ] Battery level cannot exceed the maximum amount!\n\n";
        }

    } while (current_battery > 100 || current_battery < 0);

    // User input & check (fuel)
    do {
        cout << "\n[ LOG ] Input fuel [in tons] (Maximum = 100 tons)\n>> ";
        cin >> current_fuel;
        if (current_fuel < 0) {
            cout << "[ WARNING ] Fuel cannot be less than 1 ton!\n\n";
        }
        if (current_fuel > 100) {
            cout << "\n[ WARNING ] Fuel level cannot exceed the maximum amount!\n\n";
        }
    } while (current_fuel < 0 || current_fuel > 100);

    // Check if battery/fuel level is full
    if (current_battery == 100 && current_fuel == 100) {
        cout << "\n[ LOG ] Battery and fuel are full!" << endl;
    }
    else if (current_battery == 100) {
        cout << "\n[ LOG ] Battery is full!" << endl;
    }
    else if (current_fuel == 100) {
        cout << "\n[ LOG ] Fuel is full!" << endl;
    }

    // Minimum battery and fuel check
    if (current_battery >= min_battery && current_fuel >= min_fuel) {
        cout << "[ LOG ] [ROBO-X] is ready to take off!\n" << endl;
    } else {
        cout << "\n[ WARNING ] [ROBO-X] is not ready to take off!\n" << endl;

        // Running System Check
        cout << "[ LOG ] Running System Check." << endl;
        for (int i = 1; i <= 3; i++) {
            cout << "[ LOG ] Loading" << string(i, '.') << endl;
        }
        check_system(current_battery, min_battery, current_fuel, min_fuel);
        return 0;
    }

    // Restating user's variables
    cout << "[ LOG ] Displaying battery and fuel levels.\n" << endl;
    for (int i = 1; i <= 3; i++) {
        cout << "[ LOG ] Loading" << string(i, '.') << endl;
    }
    cout << "\n[ DISPLAY ] Battery level: " << current_battery << "%." << endl;
    cout << "[ DISPLAY ] Fuel level: " << current_fuel << " tons." << endl;
    cout << "[ DISPLAY ] Number of trips possible: " << min(current_fuel / trip_fuel, current_battery / trip_battery) << endl;

    // Calculating trips
    trips_calculator(current_fuel, current_battery, trip_fuel, trip_battery);

    return 0;
}
