#include <iostream>
#include <ctime>

#include "log_item.hpp"

log_item::log_item(LevelLogger levelLog, std::string msg)
{
    std::time_t maintenant = std::time(nullptr);
    timestamp = maintenant;
    message = msg;
    levelLogger = levelLog;
    suiv = nullptr;
}

std::string log_item::levelToString(LevelLogger l)
{
    switch (l)
    {
    case LevelLogger::INFO:
        return "INFO";
    case LevelLogger::WARNING:
        return "WARNING";
    case LevelLogger::ERROR:
        return "ERROR";
    case LevelLogger::SILENT:
        return "SILENT";
    default:
        return "INCONNU";
    }
}

std::string log_item::formatterMessage()
{
    std::string timeStr = ctime(&timestamp);

    // Supprimer le '\n' ajouté par ctime à la fin
    if (!timeStr.empty() && timeStr.back() == '\n')
    {
        timeStr.pop_back();
    }

    return timeStr + " [ " + levelToString(levelLogger) + " ] : " + message;
}