#include "Logger/FileLog.h"

FileLog::FileLog(const std::string &file_name) {
    file.open(file_name, std::ios_base::app);
}

FileLog::~FileLog() {
    file.close();
}

void FileLog::print(Message msg) {
    if (file.is_open()) {
        msg.update();
        file << msg;
    }
}
