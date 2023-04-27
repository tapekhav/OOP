#ifndef LABS_MEDIATOR_H
#define LABS_MEDIATOR_H

#include "CommandReader.h"
#include "Controller.h"

class Mediator {
public:
    Mediator();
    ~Mediator();

    void start();
private:
    void init_logs(std::vector<Logger*>& loggers);
    void play(const std::map<char, Player::STEP>&);

    std::map<char, Player::STEP> set_config();

    CommandReader input;
    Controller     game;
    GameLog*    logging;
    IConfig*     config;
    int      error_flag;
};

#endif //LABS_MEDIATOR_H