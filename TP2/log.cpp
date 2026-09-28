#include "log.hpp"
#include <iostream>

log::log()
{
    historique = nullptr;
}

void log::add(LevelLogger levelLog, std::string msg)
{
    log_item *newLog = new log_item(levelLog, msg);
    if (historique == nullptr)
    {
        historique = newLog;
        return;
    }
    log_item *current = historique;
    while (current->suiv != nullptr)
    {
        current = current->suiv;
    }
    current->suiv = newLog;
}

int log::size()
{
    int count = 0;
    log_item *current = historique;
    while (current != nullptr)
    {
        current = current->suiv;
        count++;
    }
    return count;
}

void log::clear()
{
    log_item *current = historique;
    while (current != nullptr)
    {
        log_item *temp = current;
        current = current->suiv;
        delete temp;
    }
    historique = nullptr;
}

void log::print()
{
    if (historique == nullptr)
    {
        std::cout << "historique de log vide" << std::endl;
        return;
    }

    log_item *current = historique;
    while (current != nullptr)
    {
        std::cout << current->formatterMessage() << std::endl;
        current = current->suiv;
    }
}