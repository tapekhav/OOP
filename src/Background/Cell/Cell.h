#ifndef LABS_CELL_H
#define LABS_CELL_H


#include <iostream>
#include <algorithm>
#include "ChangePlayer/Box.h"
#include "ChangePlayer/Key.h"
#include "ChangePlayer/Heal.h"
#include "ChangePlayer/Trap.h"
#include "ChangeField/SetWalls.h"
#include "ChangeField/DelWalls.h"


class Cell {
public:
    Cell();

    bool get_pass() const;
    void set_pass(bool);

    void set_event(Event*);
    void update();
    Event* get_event() const;
private:
    bool pass;
    Event* event;
};

#endif
