#include "Subject.h"

void Subject::attach(GameLog *observer) {
    observers.push_back(observer);
}

void Subject::detach(GameLog *observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notify(Message msg) {
    for (auto elem : observers) {
        elem->update(msg);
    }
}
