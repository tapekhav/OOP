#ifndef LABS_ICONTROL_H
#define LABS_ICONTROL_H

#include "Player.h"
#include <map>

class IConfig : public Subject {
public:
    virtual std::map<char, Player::STEP> get_config() = 0;
    virtual ~IConfig() = default;

    std::map<char, Player::STEP> get_default();
protected:
    void is_ok();

    std::map<char, Player::STEP> control;
    const std::map<char, Player::STEP> control_default = {
            {'w', Player::STEP::UP},
            {'s', Player::STEP::DOWN},
            {'a', Player::STEP::LEFT},
            {'d', Player::STEP::RIGHT},
            {'e', Player::STEP::EXIT}
    };
};

#endif
