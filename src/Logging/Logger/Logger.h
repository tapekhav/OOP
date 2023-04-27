#ifndef LABS_LOGGER_H
#define LABS_LOGGER_H

#include <iostream>
#include <fstream>
#include "../Messages/Message.h"

class Logger {
public:
    virtual void print(Message) = 0;
    virtual ~Logger() = default;
};


#endif
