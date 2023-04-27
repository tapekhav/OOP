#ifndef LABS_LEVELSTRATEGY_H
#define LABS_LEVELSTRATEGY_H

#include "Field/FieldGenerator.h"


class LevelStrategy {
public:
    virtual Field* generate_level() = 0;
    virtual ~LevelStrategy() = default;
};

#endif