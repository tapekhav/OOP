#include "FileConfig.h"

FileConfig::FileConfig(const std::string &file_name) {
    file.open(file_name, std::ios_base::in);
}

FileConfig::~FileConfig() {
    file.close();
}

std::map<char, Player::STEP> FileConfig::get_config() {
    if (!file.is_open()) {
        notify(Message(Message::Error, "file is not open, the control is set by default."));
        return control_default;
    }

    std::string str;
    while(getline(file, str)) {
        std::string command;
        char button = '\0';

        std::istringstream stream(str);
        stream >> command >> button;

        if (command == "right:" && button != '\0') {
            control[button] = Player::STEP::RIGHT;
        }
        if (command == "left:" && button != '\0') {
            control[button] = Player::STEP::LEFT;
        }
        if (command == "up:" && button != '\0') {
            control[button] = Player::STEP::UP;
        }
        if (command == "down:" && button != '\0') {
            control[button] = Player::STEP::DOWN;
        }
        if (command == "exit:" && button != '\0') {
            control[button] = Player::STEP::EXIT;
        }
    }

    is_ok();


    return control;
}


