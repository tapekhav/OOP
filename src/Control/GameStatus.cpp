#include "GameStatus.h"

void GameStatus::set_status_off(STATUS status) {
    this->status = status;
    this->notify(Message(Message::GameStatus, "game status is OFF"));
}

void GameStatus::set_status_on() {
    this->status = ON;
    this->notify(Message(Message::GameStatus, "game status is ON"));
}

GameStatus::STATUS GameStatus::get_status() const {
    return status;
}
