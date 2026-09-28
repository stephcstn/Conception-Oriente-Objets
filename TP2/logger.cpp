#include <iostream>
#include "logger.hpp"

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

logger::logger(log &historique)
    : filtreLog(INFO), l(historique)
{
}

logger::logger(log &historique, LevelLogger filtreLogger) : l(historique)
{
    filtreLog = filtreLogger;
}

void logger::makeLog(LevelLogger levelLog, std::string msg)
{
    if (levelLog >= filtreLog)
    {
        l.add(levelLog, msg); // 'l' est la référence vers historique1 initialisée dans le constructeur
    }
}