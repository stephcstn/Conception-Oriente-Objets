#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <ctime>

enum LevelLogger
{
    INFO,
    WARNING,
    ERROR
};

class Logger
{
private:
    std::string nameLogger;
    LevelLogger levelLogger;
    std::time_t timestamp;
    std::string message;

public:
    Logger(std::string name, LevelLogger level, std::string msg);
    // void printLog();
};

#endif