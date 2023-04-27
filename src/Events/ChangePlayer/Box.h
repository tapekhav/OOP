#ifndef LABS_BOX_H
#define LABS_BOX_H

#include "EventPlayer.h"

class Box final : public EventPlayer {
public:
    explicit Box(Player*);
    void execute() final;
};


#endif //LABS_BOX_H
