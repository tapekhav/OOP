#include "Player.h"

Player::Player(int lvl)
    : health(lvl * 5), xp(0), lvl(lvl), num_of_keys(0) {}

int Player::get_health() const {
    return health;
}

int Player::get_xp() const {
    return xp;
}

int Player::get_lvl() const {
    return lvl;
}

int Player::get_keys() const {
    return num_of_keys;
}

void Player::set_health(int health) {
    this->health = health;
    notify(Message(Message::Game, "player's health was changed", this->health));
}

void Player::set_xp(int xp) {
    this->xp = xp;
    notify(Message(Message::Game, "player's xp was changed", this->xp));
}

void Player::add_lvl() {
    ++lvl;
    notify(Message(Message::Game, "player's lvl was changed", lvl));
}

void Player::add_key() {
    ++num_of_keys;
    notify(Message(Message::Game, "player's count of keys was changed", num_of_keys));
}
