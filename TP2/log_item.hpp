#ifndef LOG_ITEM_HPP
#define LOG_ITEM_HPP

class log_item{
    public:
        LevelLogger levelLogger;
        std::time_t timestamp;
        std::string message;
        log_item *suiv;
        log_item(LevelLogger levelLog, std::string msg);
}

#endif