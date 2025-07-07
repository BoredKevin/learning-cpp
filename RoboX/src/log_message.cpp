#include <iostream>
#include <string>
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
    cout << prefix << message << endl;
}
