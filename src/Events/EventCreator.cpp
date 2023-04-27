#include "EventCreator.h"

EventCreator::EventCreator(Player *player, Field *field) : player(player), field(field) {}

void EventCreator::set_events() {
    std::vector<std::pair<int, int>> array;
    std::mt19937 rng{std::random_device{}()};
    std::uniform_int_distribution<int> damage(1, player->get_health());

    set_cell(new Box(player), array);
    set_cell(new Heal(player), array);
    set_cell(new Trap(player, damage(rng)), array);
    set_cell(new SetWalls(field), array);
    set_cell(new DelWalls(field), array);

    field->get_cur_cell(field->get_width() - 1, 0).set_event(new Key(player));
    field->get_cur_cell(0, field->get_height() - 1).set_event(new Key(player));
}

void EventCreator::set_cell(Event* event, std::vector<std::pair<int, int>>& array) {
    std::pair<int, int> coordinates = get_coordinates(array);
    field->get_cur_cell(coordinates.second, coordinates.first).set_event(event);
}

std::pair<int, int> EventCreator::get_coordinates(std::vector<std::pair<int, int>>& array) {
    std::mt19937 rng{std::random_device{}()};
    std::uniform_int_distribution<int> gen_height(1, field->get_height() - 2);
    std::uniform_int_distribution<int> gen_width(1, field->get_width() - 2);

    std::pair<int, int> pair = {gen_height(rng), gen_width(rng)};
    for (size_t i = 0; i != array.size(); ++i) {
        if (array[i] == pair) {
            pair = {gen_height(rng), gen_width(rng)};
            i = 0;
        }
    }
    array.push_back(pair);

    return pair;
}
