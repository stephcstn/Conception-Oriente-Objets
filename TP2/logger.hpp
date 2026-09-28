#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <filesystem>
#include "log_item.hpp"
#include "log.hpp"
class logger
{
private:
    std::filesystem::path filePath;
    LevelLogger filtreLog;
    int TailleMax = 1000;
    log &l;

public:
    logger(log &historique);
    logger(log &historique, LevelLogger filtreLogger);
    void makeLog(LevelLogger levelLog, std::string msg);
    
};

#endif