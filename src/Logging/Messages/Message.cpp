#include "Message.h"

Message::Message(Prefix prefix, const std::string& info, int num) {
    this->prefix = prefix;
    this->info = info;
    this->num = num;
}

std::string Message::get_msg() {
    return info;
}

Message::Prefix Message::get_prefix() const {
    return prefix;
}

std::ostream &operator<<(std::ostream& out, Message& msg) {
    out << msg.prefix_map.find(msg.prefix)->second;
    out << msg.get_msg();
    return out;
}

void Message::update() {
    if (num != -1) {
        info += ": " + std::to_string(num);
    }
    info += "\n";
}
