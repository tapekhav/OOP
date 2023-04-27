#include "Mediator.h"


Mediator::Mediator()  : logging(new GameLog), config(new FileConfig), error_flag(0) {}

Mediator::~Mediator() {
    delete logging;
    delete config;
}

void Mediator::start() {
    input.get_src();
    game.set_level(input.get_num_level());
    auto vec = input.read_loggers();
    init_logs(vec);
    game.set_status_on();

    auto settings = set_config();

    play(settings);

    for (auto elem : vec)
        delete elem;
}

void Mediator::init_logs(std::vector<Logger*>& loggers) {
    int flag = 0;
    if (input.get_game_log() == 'y') {
        logging->add_subject(game.get_player());
        logging->add_subject(game.get_field());
        logging->add_level(Message::Game);
        flag = 1;
    }

    if (input.get_status_log() == 'y') {
        logging->add_subject(game.get_game_status());
        logging->add_level(Message::GameStatus);
    }

    if (input.get_error_log() == 'y') {
        if (flag == 0) logging->add_subject(game.get_field());
        logging->add_subject(&input);
        logging->add_level(Message::Error);
        error_flag = 1;
    }

    logging->set_loggers(loggers);
}

void Mediator::play(const std::map<char, Player::STEP>& settings) {
    while(input.get_step() != Player::EXIT && game.get_status() == GameStatus::ON) {
        input.read_step(settings);
        game.set_step(input.get_step());

        game.check_win_game();
        game.check_end_game();
    }
}

std::map<char, Player::STEP> Mediator::set_config() {
    std::map<char, Player::STEP> settings;
    if (input.read_config() == 'y') {
        settings = config->get_default();
    } else {
        delete config;
        config = new FileConfig(input.read_file_name());
        if (error_flag == 1) logging->add_subject(config);
        settings = config->get_config();
    }

    return settings;
}
