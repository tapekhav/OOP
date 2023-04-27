#ifndef LABS_RULEFIELDSIZE_H
#define LABS_RULEFIELDSIZE_H

#include "Field/Field.h"

template<int width = 10, int height = 10>
class RuleFieldSize {
public:
    void operator()(Field* field) {
        delete field;
        field = new Field(width, height);
    }
};

#endif
