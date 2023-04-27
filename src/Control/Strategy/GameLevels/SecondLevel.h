#ifndef LABS_SECONDLEVEL_H
#define LABS_SECONDLEVEL_H

#include "../LevelStrategy.h"

class SecondLevel final : public LevelStrategy {
public:
    Field* generate_level() final;
};


#endif
