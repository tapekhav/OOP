#include "Trap.h"

Trap::Trap(Player *player, int damage) {
    this->player = player;
    this->damage = damage;
}

void Trap::execute() {
    player->set_health(player->get_health() - damage);
}