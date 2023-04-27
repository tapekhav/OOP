#include "Key.h"

Key::Key(Player *player) {
    this->player = player;
}

void Key::execute() {
    player->add_key();
}
