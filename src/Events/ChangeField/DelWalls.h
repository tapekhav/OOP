#ifndef LABS_DELWALLS_H
#define LABS_DELWALLS_H

#include "EventField.h"
#include "Field/Field.h"

class DelWalls final : public EventField {
public:
    explicit DelWalls(Field*);
    void execute() final;
};


#endif
