#ifndef LABS_COMMANDREADER_H
#define LABS_COMMANDREADER_H

#include <iostream>
#include "../Characters/Player.h"
#include "../Logging/Logger/FileLog.h"
#include "../Logging/LogLevel/Subject.h"
#include "ControlCommands/TerminalController.h"
#include "Config/FileConfig.h"

class CommandReader : public Subject {
public:
    ~CommandReader();

    void read_step(const std::map<char, Player::STEP>&);
    void read_size();
    char read_char();
    char read_config();
    void get_src();

    char get_num_level();

    std::vector<Logger*> read_loggers();
    char get_game_log();
    char get_error_log();
    char get_status_log();
    std::string read_file_name() const;

    int get_height() const;
    int get_width() const;
    Player::STEP get_step() const;
private:
    void check(int&);

    IController* control;
    int height;
    int width;
    Player::STEP step;
};

#endif