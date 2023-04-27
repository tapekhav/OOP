#ifndef LABS_TERMINALCONTROLLER_H
#define LABS_TERMINALCONTROLLER_H

#include <iostream>
#include "IController.h"

class TerminalController final : public IController {
public:
    char get_step() final;
    char get_char() final;
    int get_width() final;
    int get_height() final;
    char get_cfg() final;
    std::string get_file_name() final;
    char get_logs() final;
    char get_game_log() final;
    char get_error_log() final;
    char get_status_log() final;
    ~TerminalController() final = default;
    char get_num_level() final;


    char read_char();
    int read_num();
};


#endif