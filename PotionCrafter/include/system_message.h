#ifndef SYSTEM_MESSAGE_H
#define SYSTEM_MESSAGE_H
#include <string>


enum SystemLevel
{
    SYSTEM,
    DISPLAY,
    INPUT
};

void system_message(SystemLevel level, const std::string& message);

#endif // SYSTEM_MESSAGE_H
