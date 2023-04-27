#include "IConfig.h"


std::map<char, Player::STEP> IConfig::get_default() {
    return control_default;
}

void IConfig::is_ok() {
    if (control.size() < 5) {
        control = control_default;
        notify(Message(Message::Error, "the config is set incorrectly, the control is set by default."));
    }
}
