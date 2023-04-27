#ifndef LABS_GAMESTATUS_H
#define LABS_GAMESTATUS_H

#include "../Logging/LogLevel/Subject.h"

class GameStatus : public Subject {
public:
    enum STATUS {
        ON,
        LOSE,
        WIN
    };

    void set_status_off(GameStatus::STATUS);
    void set_status_on();
    STATUS get_status() const;
private:
    STATUS status;
};


#endif
