#ifndef LOG_ITEM_HPP
#define LOG_ITEM_HPP

enum LevelLogger
{
    INFO = 0,
    WARNING = 1,
    ERROR = 2,
    SILENT = 3,
};
class log_item
{
public:
    LevelLogger levelLogger;
    time_t timestamp;
    std::string message;
    log_item *suiv;
    log_item(LevelLogger levelLog, std::string msg);
    std::string formatterMessage();
    std::string levelToString(LevelLogger l);
};

#endif