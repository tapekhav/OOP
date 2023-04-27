#ifndef LABS_EVENTFIELD_H
#define LABS_EVENTFIELD_H

class Field;
#include "../../Events/Event.h"

class EventField : public Event {
public:
    void execute() override = 0;
protected:
    Field* field;
};

#endif
