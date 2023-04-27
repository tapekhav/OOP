#ifndef LABS_LEVELCONTEXT_H
#define LABS_LEVELCONTEXT_H

#include <memory>
#include "LevelStrategy.h"


class LevelContext {
public:
    explicit LevelContext(std::unique_ptr<LevelStrategy> &&strategy = {});
    void set_strategy(std::unique_ptr<LevelStrategy> &&strategy);

    void set_level();

    Field* get_field();
private:
    Field* field;
    std::unique_ptr<LevelStrategy> level;
};


#endif
