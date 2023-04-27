#ifndef LABS_RULESPAWNHERO_H
#define LABS_RULESPAWNHERO_H

#include <utility>
#include <Field/Field.h>

template<int x = 0, int y = 0>
class RuleSpawnPlayer {
public:
    void operator()(Field* field) {
        if (field->get_cur_cell(x, y).get_pass() && field->get_cur_cell(x, y).get_event() == nullptr)
            field->set_player_location(x, y);
        else
            field->set_player_location(0, 0);
    }
};


#endif
