#include <iostream>

#include "log.hpp"
#include "logger.hpp"

int main()
{
    log historique1;
    logger monLogger(historique1, LevelLogger::INFO);

    monLogger.makeLog(LevelLogger::INFO, "prout message");
    monLogger.makeLog(LevelLogger::INFO, "prout message");
    monLogger.makeLog(LevelLogger::ERROR, "prout message");
    monLogger.makeLog(LevelLogger::WARNING, "prout message");
    monLogger.makeLog(LevelLogger::ERROR, "prout message");

    historique1.print();

    return 0;
}