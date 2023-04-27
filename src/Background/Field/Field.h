#ifndef LABS_FIELD_H
#define LABS_FIELD_H

class Cell;

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include "Cell/Cell.h"
#include "Player.h"
#include "LogLevel/GameLog.h"
#include "Logger/ConsoleLog.h"
#include "EventCreator.h"

class Field : public Subject {
public:
    explicit Field(int width = 10, int height = 10);
    ~Field();
    Field(const Field&);
    Field& operator=(const Field&);
    Field(Field&& other);
    Field& operator=(Field&&);

    void generate_walls();
    void delete_walls();

    void change_player_location(Player::STEP);
    std::pair<int, int> get_player_location() const;
    void set_player_location(int, int);

    int get_height() const;
    int get_width()  const;
    Cell& get_cur_cell(int, int);
    Player* get_player();
private:
    void swap(Field&);

    Player* player;
    std::vector<std::vector<Cell>> field;
    int height;
    int width;
    std::pair<int, int> player_location;
};

#endif