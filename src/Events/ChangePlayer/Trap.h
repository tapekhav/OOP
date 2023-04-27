#ifndef LABS_TRAP_H
#define LABS_TRAP_H

#include "EventPlayer.h"
#include <random>

class Trap final : public EventPlayer {
public:
    explicit Trap(Player*, int);
    void execute() final;
private:
    int damage;
};


#endif //LABS_TRAP_H
