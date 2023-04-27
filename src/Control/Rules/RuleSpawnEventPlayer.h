#ifndef LABS_RULESPAWNBOX_H
#define LABS_RULESPAWNBOX_H


#include "Field/Field.h"

template<class EP, int magic_number, int max_count = 1>
class RuleSpawnEventPlayer {
public:
    void operator()(Field* field) {
        auto player = field->get_player();
        int k = 0;

        for (int i = 1; i != field->get_height() - 1; ++i) {
            for (int j = 0; j != field->get_width() - 1; ++j) {
                if (k == max_count) return;
                if ((magic_number / i) % field->get_height() % 7 == 0
                && (magic_number / (j + 1)) % field->get_width() % 7 == 0) {
                    field->get_cur_cell(j, i).set_pass(true);
                    field->get_cur_cell(j, i).set_event(new EP(player));
                    ++k;
                }
            }
        }
    }
};

#endif
