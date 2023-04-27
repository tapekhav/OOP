#ifndef LABS_EVENTPLAYER_H
#define LABS_EVENTPLAYER_H

#include "../../Characters/Player.h"
#include "../Event.h"

class EventPlayer : public Event {
public:
    void execute() override = 0;
protected:
    Player* player;
};

#endif
