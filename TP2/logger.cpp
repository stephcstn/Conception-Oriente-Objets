#include <iostream>
#include "logger.hpp"

Logger::Logger(std::string name, LevelLogger level, std::string msg)
{
    nameLogger = name;
    levelLogger = level;
    message = msg;
}

// void Logger::printLog()
// {
//     // std::time_t now = std::time(nullptr);
//     // std::tm *localTime = std::localtime(&now);

//     // char buffer[80];
//     // std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);

//     std::string levelStr;
//     switch (levelLogger)
//     {
//     case INFO:
//         levelStr = "INFO";
//         break;
//     case WARNING:
//         levelStr = "WARNING";
//         break;
//     case ERROR:
//         levelStr = "ERROR";
//         break;
//     }

//     std::cout << message << std::endl;
// }
