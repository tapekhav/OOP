#ifndef LABS_CONTROLLER_H
#define LABS_CONTROLLER_H

#include "Config/FileConfig.h"
#include "Field/FieldView.h"
#include "GameStatus.h"
#include "Strategy/LevelContext.h"

class Controller {
public:
    Controller();
    ~Controller();

    void set_step(Player::STEP);

    Player*     get_player();
    Field*      get_field();
    GameStatus* get_game_status();

    void check_win_game();
    void check_end_game();
    void set_status_on();
    GameStatus::STATUS get_status() const;

    void set_level(char);
private:
    LevelContext   context;
    FieldView   field_view;
    GameStatus game_status;
};


#endif