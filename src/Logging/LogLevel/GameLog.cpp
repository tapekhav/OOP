#include "GameLog.h"


void GameLog::add_level(Message::Prefix level) {
    this->levels.push_back(level);
}

void GameLog::update(Message &msg) {
    for (auto elem : loggers)
        for (const auto& lvl : levels) {
            if (msg.get_prefix() == lvl) {
                elem->print(msg);
                break;
            }
        }
}

void GameLog::set_loggers(std::vector<Logger *>& loggers) {
    for (auto elem : loggers)
        this->loggers.push_back(elem);
}

void GameLog::add_subject(Subject *subject) {
    subjects.push_back(subject);
    subject->attach(this);
}
