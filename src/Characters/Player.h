#ifndef LABS_PLAYER_H
#define LABS_PLAYER_H

#include <algorithm>
#include "../Logging/LogLevel/Subject.h"

class Player : public Subject {
public:
    enum STEP {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        STOP,
        EXIT
    };
    explicit Player(int lvl = 1);

    int get_health() const;
    int get_lvl()    const;
    int get_xp()     const;
    int get_keys()   const;

    void set_health(int);
    void set_xp(int);
    void add_lvl();
    void add_key();
private:
    int health;
    int xp;
    int lvl;
    int num_of_keys;
};

#endif //LABS_PLAYER_H
