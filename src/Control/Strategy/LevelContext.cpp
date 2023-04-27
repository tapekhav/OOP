#include "LevelContext.h"

LevelContext::LevelContext(std::unique_ptr<LevelStrategy> &&strategy) : level(std::move(strategy)) {}

void LevelContext::set_strategy(std::unique_ptr<LevelStrategy> &&strategy) {
    level = std::move(strategy);
}

void LevelContext::set_level() {
    field = level->generate_level();
}

Field *LevelContext::get_field() {
    return field;
}

