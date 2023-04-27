#ifndef TRASH_1382_SUBJECT_H
#define TRASH_1382_SUBJECT_H

class GameLog;

#include "GameLog.h"
#include "../Logger/Logger.h"
#include "../Logger/ConsoleLog.h"
#include <vector>
#include <algorithm>

class Subject {
public:
    void attach(GameLog *);

    void detach(GameLog *);
    void notify(Message);
private:
    std::vector<GameLog *> observers;
};

#endif
