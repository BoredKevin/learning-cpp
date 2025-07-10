#include <iostream>
#include <string>

using namespace std;

enum SystemLevel {
    SYSTEM,
    DISPLAY,
    INPUT
};

void system_message(SystemLevel level, const string& message)
{
    string prefix;

    switch (level)
    {
    case SYSTEM:
        prefix = "[ SYSTEM ] ";
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
