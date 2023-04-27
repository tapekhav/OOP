#ifndef LABS_GAMELOG_H
#define LABS_GAMELOG_H

class Subject;

#include <vector>
#include <algorithm>
#include "../Logger/Logger.h"
#include "Subject.h"

class GameLog {
public:
    void add_subject(Subject*);
    void add_level(Message::Prefix);
    void set_loggers(std::vector<Logger*>&);
    void update(Message &);
private:
    std::vector<Subject*> subjects;
    std::vector<Logger*> loggers;
    std::vector<Message::Prefix> levels;
};

#endif
