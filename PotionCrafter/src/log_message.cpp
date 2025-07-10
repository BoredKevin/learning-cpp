#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>

using namespace std;

enum LogLevel {
    LOG,
    WARNING,
    DISPLAY,
    INPUT
};

void log_message(LogLevel level, const string& message) {
    string prefix;

    switch (level) {
    case LOG:
        prefix = "[ LOG ] ";
        break;
    case WARNING:
        prefix = "[ WARNING ] ";
        break;
    case DISPLAY:
        prefix = "[ DISPLAY ] ";
        break;
    case INPUT:
        prefix = "[ INPUT ] ";
        break;
    }

    auto now = chrono::system_clock::now();
    time_t time_t = chrono::system_clock::to_time_t(now);

    cout << put_time(localtime(&time_t), "[ %Y-%m-%d || %H:%M:%S ] ") << prefix << message << endl;
}
