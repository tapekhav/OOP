#include "Logger/ConsoleLog.h"

void ConsoleLog::print(Message msg) {
    msg.update();
    std::cout << msg;
}
