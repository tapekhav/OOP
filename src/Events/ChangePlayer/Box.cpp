#include "Box.h"

Box::Box(Player *player) {
    this->player = player;
}


void Box::execute() {
    player->set_xp(player->get_xp() + 10);
    if (player->get_xp() == player->get_lvl() * 10) {
        player->add_lvl();
        player->set_xp(0);
        player->set_health(player->get_lvl() * 5);
    }
}