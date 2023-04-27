#include "Field.h"

Field::Field(int width, int height) : width(width), height(height), player(new Player) {
    for (size_t i = 0; i != height; ++i) {
        field.emplace_back();
        for (size_t j = 0; j != width; ++j)
            field.at(i).emplace_back();
    }
}

Field::~Field() {
    for (size_t i = 0; i != height; ++i)
        for (size_t j = 0; j != width; ++j)
            field.at(i).at(j).set_event(nullptr);

    delete player;
}

Field::Field(const Field &other)
    : width(other.width), height(other.height), player_location(other.player_location) {
    for(size_t i = 0; i != height; ++i) {
        field.emplace_back();
        for(size_t j = 0; j != width; ++j) {
            field.at(i).push_back(other.field.at(i).at(j));
        }
    }
}

void Field::swap(Field &other) {
    std::swap(width, other.width);
    std::swap(height, other.height);
    std::swap(field, other.field);
    std::swap(player_location, other.player_location);
    std::swap(player, other.player);
}

Field& Field::operator=(const Field &other) {
    if (this != &other)
        Field(other).swap(*this);

    return *this;
}

Field::Field(Field&& other) {
    this->swap(other);
}

Field& Field::operator=(Field&& other) {
    if (this != &other)
        this->swap(other);
    return *this;
}

Cell& Field::get_cur_cell(int x, int y) {
    return field.at(y).at(x);
}

std::pair<int, int> Field::get_player_location() const {
    return player_location;
}

void Field::set_player_location(int x, int y) {
    player_location.first = x;
    player_location.second = y;
}

void Field::generate_walls() {
    player_location = {0, 0};
    for (int i = 0; i != height - 1; ++i) {
        for (int j = 1; j != width - 1; ++j) {
            std::mt19937 rng{std::random_device{}()};
            std::uniform_int_distribution<int> dist(1, 10);
            field.at(i).at(j).set_event(nullptr);
            if (dist(rng) == 1)
                field.at(i).at(j).set_pass(false);
        }
    }
}

void Field::delete_walls() {
    for (int i = 0; i != height; ++i)
        for (int j = 0; j != width; ++j)
            field.at(i).at(j).set_pass(true);
}

void Field::change_player_location(Player::STEP s) {
    auto tmp = player_location;

    field.at(player_location.second).at(player_location.first).set_event(nullptr);

    switch(s) {
        case Player::UP:
            tmp.second--;
            break;
        case Player::DOWN:
            tmp.second++;
            break;
        case Player::LEFT:
            tmp.first--;
            break;
        case Player::RIGHT:
            tmp.first++;
            break;
        default:
            break;
    }

    tmp.first %= width;
    tmp.second %= height;

    if (tmp.first < 0) tmp.first += width;
    if (tmp.second < 0) tmp.second += height;

    if (field.at(tmp.second).at(tmp.first).get_pass()) {
        player_location = tmp;
    }
    else {
        this->notify(Message(Message::Error, "this cell is impassable"));
        return;
    }

    if (field.at(player_location.second).at(player_location.first).get_event() != nullptr) {
        this->notify(Message(Message::Game, "event was played"));
    }

    field.at(player_location.second).at(player_location.first).update();

    if (s != Player::EXIT) {
        this->notify(Message(Message::Game, "player change location"));
    }
}

int Field::get_height() const {
    return height;
}

int Field::get_width() const {
    return width;
}

Player *Field::get_player() {
    return player;
}