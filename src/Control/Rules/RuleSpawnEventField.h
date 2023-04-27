#ifndef LABS_RULEDELWALLS_H
#define LABS_RULEDELWALLS_H

#include "Field/Field.h"

template<class EF, int magic_number>
class RuleSpawnEventField {
public:
    void operator()(Field *field) {
        int flag = 0;

        for (int i = 1; i != field->get_height() - 1; ++i) {
            for (int j = 0; j != field->get_width() - 1; ++j) {
                if (flag == 1) return;
                if ((i * magic_number) % field->get_height() % 7 == 4
                && (j * magic_number) % field->get_width() % 7 == 4) {
                    field->get_cur_cell(j, i).set_pass(true);
                    field->get_cur_cell(j, i).set_event(new EF(field));
                    flag = 1;
                }
            }
        }
    }
};

#endif
