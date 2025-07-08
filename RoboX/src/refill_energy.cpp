#include <iostream>
#include <string>
#include "refill_energy.h"
#include "log_message.h"
#include "input_validator.h"
#include "energy_display.h"
#include "log_loading.h"
#include <stdlib.h>

using namespace std;

int refill_energy(int& battery, int& fuel, int MAX_BATTERY, int MAX_FUEL)
{
    int refill;
    int recharge;
    char command;

    log_message(DISPLAY, "Do you want to refill energy? (y/n)");
    cout << ">> ";
    cin >> command;

    if ('y' == command || 'Y' == command) {
        log_message(INPUT, "Enter 1 to refill fuel, enter 2 to refill battery.");
        cout << ">> ";
        cin >> command;

        if ('1' == command) {
            energy_display(battery, fuel, MAX_BATTERY, MAX_FUEL);
            refill = get_valid_input("How much fuel do you want to fill?", 1, 100 - fuel, "Added fuel");

            log_loading("Refilling fuel");

            fuel += refill;

            log_message(LOG, "You have increased your fuel level by " + to_string(refill) + " tons.");

            return fuel;
        }
    }

        if ('2' == command) {
                energy_display(battery, fuel, MAX_BATTERY, MAX_FUEL);
                recharge = get_valid_input("How much battery do you want to charge?", 1, MAX_BATTERY - battery, "Added battery");

                log_loading("Recharging battery");

                battery += recharge;

                log_message(LOG, "You have increased your battery level by " + to_string(recharge) + "%.");

                return battery;
            }

    else {
        log_message(WARNING, "Energy is low!");
        log_message(WARNING, "Shutting down system...");
        log_loading("Powering off engine");
        cout << "\n";
        log_message(LOG, "Engine powered off.");
    }

}
