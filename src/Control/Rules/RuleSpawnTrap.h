#ifndef LABS_RULESPAWNTRAP_H
#define LABS_RULESPAWNTRAP_H

#include <utility>
#include "Field/Field.h"
#include "../Characters/Player.h"

template<int magic_number, int damage, int max_count>
class RuleSpawnTrap {
public:
    void operator()(Field* field) {
        auto player = field->get_player();
        int k = 0;

        for (int i = 1; i != field->get_height() - 1; ++i) {
            for (int j = 0; j != field->get_width() - 1; ++j) {
                if (k == max_count) return;
                if ((i * magic_number) % field->get_height() == j + 1
                    && field->get_cur_cell(j, i).get_event() == nullptr) {
                    field->get_cur_cell(j, i).set_event(new Trap(player, damage));
                    field->get_cur_cell(j, i).set_pass(true);
                    ++k;
                }
            }
        }
    }
};

#endif
