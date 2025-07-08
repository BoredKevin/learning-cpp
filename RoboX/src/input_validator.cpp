#include "input_validator.h"
#include <iostream>
#include <string>
#include "log_message.h"

using namespace std;

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
