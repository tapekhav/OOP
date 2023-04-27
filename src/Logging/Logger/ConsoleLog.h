#ifndef LABS_CONSOLELOG_H
#define LABS_CONSOLELOG_H

#include "../Logger/Logger.h"
#include "../Messages/Message.h"

class ConsoleLog : public Logger {
public:
    void print(Message) override;
};


#endif
