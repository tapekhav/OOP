#ifndef LABS_EVENT_H
#define LABS_EVENT_H

#include "../Logging/LogLevel/Subject.h"

class Event : public Subject {
public:
    virtual void execute() = 0;
    virtual ~Event() = default;
};

#endif
