#include "Controller.h"
#include "Strategy/GameLevels/FirstLevel.h"
#include "Strategy/GameLevels/SecondLevel.h"


Controller::Controller() : field_view(nullptr), game_status(GameStatus()), context() {}

Controller::~Controller() {
    delete context.get_field();
}


void Controller::set_level(char num) {
    if (num == '1') {
        context.set_strategy(std::make_unique<FirstLevel>());
    } else {
        context.set_strategy(std::make_unique<SecondLevel>());
    }
    context.set_level();

    field_view = FieldView(context.get_field());
    field_view.update();
}


void Controller::set_step(Player::STEP step) {
    context.get_field()->change_player_location(step);
    if (step != Player::EXIT) {
        field_view.update();
    }
}

Player *Controller::get_player() {
    return context.get_field()->get_player();
}

Field *Controller::get_field() {
    return context.get_field();
}

GameStatus *Controller::get_game_status() {
    return &game_status;
}

void Controller::check_end_game() {
    if (get_player()->get_health() <= 0)
        game_status.set_status_off(GameStatus::LOSE);
}

void Controller::check_win_game() {
    if (get_player()->get_keys() == 2)
        game_status.set_status_off(GameStatus::WIN);
}

GameStatus::STATUS Controller::get_status() const {
    return game_status.get_status();
}

void Controller::set_status_on() {
    game_status.set_status_on();
}
