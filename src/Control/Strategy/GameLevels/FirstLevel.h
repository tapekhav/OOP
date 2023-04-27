#ifndef LABS_FIRSTLEVEL_H
#define LABS_FIRSTLEVEL_H

#include "../LevelStrategy.h"

class FirstLevel final : public LevelStrategy {
public:
    Field* generate_level() final;
};


#endif
