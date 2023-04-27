#ifndef LABS_RULESETWALLS_H
#define LABS_RULESETWALLS_H

#include "../Background/Field/Field.h"

template<int magic_number>
class RuleSpawnWalls {
public:
    void operator()(Field* field) {
        for(int i = 1; i != field->get_height() - 1; ++i)
           for(int j = 0; j != field->get_width() - 1; ++j)
               if ((magic_number/i) % field->get_height() % 3 == 0
               && (magic_number/(j + 1)) % field->get_width() % 3 == 0) {
                   field->get_cur_cell(j, i).set_pass(false);
                   field->get_cur_cell(j, i).set_event(nullptr);
               }
    }
};


#endif
