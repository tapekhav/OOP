#ifndef LABS_RULESPAWNKEYS_H
#define LABS_RULESPAWNKEYS_H

#include <utility>
#include "Field/Field.h"

template<int magic_number>
class RuleSpawnKeys {
public:
    void operator()(Field* field) {
        auto player = field->get_player();

        int tmp_number = magic_number;
        if (tmp_number < 0) tmp_number *= -1;

        tmp_number %= field->get_height();
        tmp_number %= field->get_width();

        field->get_cur_cell(field->get_width() - 1, tmp_number).set_pass(true);
        field->get_cur_cell(field->get_width() - 1, tmp_number).set_event(new Key(player));

        field->get_cur_cell(tmp_number, field->get_height() - 1).set_pass(true);
        field->get_cur_cell(tmp_number, field->get_height() - 1).set_event(new Key(player));
    }
};

#endif

