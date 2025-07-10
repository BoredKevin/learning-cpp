#ifndef LOG_MESSAGE_H
#define LOG_MESSAGE_H

#include <string>

enum LogLevel {
    LOG,
    WARNING,
    DISPLAY,
    INPUT
};

void log_message(LogLevel level, const std::string& message);

#endif // LOG_MESSAGE_H
