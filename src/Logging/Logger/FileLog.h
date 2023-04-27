#ifndef LABS_FILELOG_H
#define LABS_FILELOG_H

#include "../Logger/Logger.h"

class FileLog : public Logger {
public:
    explicit FileLog(const std::string &file_name = "input.txt");
    ~FileLog() override;

    void print(Message) override;
private:
    std::ofstream file;
};


#endif
