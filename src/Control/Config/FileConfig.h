#ifndef LABS_GETCONTROL_H
#define LABS_GETCONTROL_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "IConfig.h"

class FileConfig final : public IConfig {
public:
    explicit FileConfig(const std::string& file_name = "check.txt");
    std::map<char, Player::STEP> get_config() final;
    ~FileConfig() final;
private:
    std::ifstream file;
};


#endif
