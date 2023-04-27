#include "CommandReader.h"


CommandReader::~CommandReader() {
    delete control;
}

void CommandReader::read_size() {
    height = control->get_height();
    check(height);

    width = control->get_width();
    check(width);
}


void CommandReader::read_step(const std::map<char, Player::STEP>& config) {
    auto elem = config.find(control->get_step());
    if (elem != config.end()) {
        step = elem->second;
        return;
    }
    if (elem == config.end()) {
        step = Player::STEP::STOP;
        notify(Message(Message::Error, "step was entered incorrectly"));
    }
}

char CommandReader::read_char() {
    return control->get_char();
}

void CommandReader::get_src() {
    char ch;
    std::cout << "Откуда будет считываться управление? Любой символ - из консоли. ";
    std::cin >> ch;
    if (ch) control = new TerminalController;
}

char CommandReader::get_game_log() {
    return control->get_game_log();
}

char CommandReader::get_error_log() {
    return control->get_error_log();
}

char CommandReader::get_status_log() {
    return control->get_status_log();
}

std::vector<Logger*> CommandReader::read_loggers() {
    char number;
    std::vector<Logger*> loggers;

    number = control->get_logs();

    if (number == '1') {
        loggers.push_back(new ConsoleLog);
    }
    if (number == '2') {
        loggers.push_back(new FileLog(read_file_name()));
    }
    if (number == '3') {
        loggers.push_back(new ConsoleLog);
        loggers.push_back(new FileLog(read_file_name()));
    }

    return loggers;
}

std::string CommandReader::read_file_name() const {
    return control->get_file_name();
}

char CommandReader::read_config() {
    return control->get_cfg();
}


int CommandReader::get_height() const {
    return height;
}

int CommandReader::get_width() const {
    return width;
}

Player::STEP CommandReader::get_step() const {
    return step;
}

void CommandReader::check(int &arg) {
    if (arg < 10 || arg > 25) {
        notify(Message(Message::Error, "the value was entered incorrectly"));
        arg = 10;
    }
}

char CommandReader::get_num_level() {
    return control->get_num_level();
}
