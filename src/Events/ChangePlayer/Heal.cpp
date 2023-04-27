#include "Heal.h"

Heal::Heal(Player *player) {
    this->player = player;
}

void Heal::execute() {
    int max_health = player->get_lvl() * 5;
    if (player->get_health() < max_health)
        player->set_health(player->get_health() + 1);
    else
        player->set_health(max_health);
}
