#ifndef LABS_HEAL_H
#define LABS_HEAL_H

#include "EventPlayer.h"

class Heal final : public EventPlayer {
public:
    explicit Heal(Player*);
    void execute() final;
};


#endif //LABS_HEAL_H
