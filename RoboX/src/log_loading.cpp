#include "log_loading.h"
#include "log_message.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

void log_loading(const string& message, int times) {
    times = 3;
    for (int i = 1; i <= times; ++i) {
        log_message(LOG, message + string(i, '.'));
        _sleep(1000);
    }
    cout << "\n";
}
