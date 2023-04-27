#ifndef LABS_EVENTCREATOR_H
#define LABS_EVENTCREATOR_H

#include "Field/Field.h"

class EventCreator {
public:
    explicit EventCreator(Player*, Field*);

    std::pair<int, int> get_coordinates(std::vector<std::pair<int, int>>&);

    void set_events();
    void set_cell(Event*, std::vector<std::pair<int, int>>&);
private:
    Player* player;
    Field* field;
};


#endif
