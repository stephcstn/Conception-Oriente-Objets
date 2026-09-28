#ifndef LOG_HPP
#define LOG_HPP

#include <iostream>
#include <string>
#include "log_item.hpp"

class log
{
private:
    log_item *historique;

public:
    log();
    void add(LevelLogger levelLog, std::string msg);
    int size();
    void clear();
    void print();
};

#endif