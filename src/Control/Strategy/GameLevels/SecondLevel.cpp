#include "SecondLevel.h"

Field *SecondLevel::generate_level() {
    FieldGenerator<RuleFieldSize<>,
                   RuleSpawnKeys<22>,
                   RuleSpawnPlayer<>,
                   RuleSpawnEventField<SetWalls, 13>,
                   RuleSpawnEventField<DelWalls, 12>,
                   RuleSpawnWalls<773>,
                   RuleSpawnTrap<89, 5, 10>,
                   RuleSpawnEventPlayer<Box, 51>,
                   RuleSpawnEventPlayer<Heal, 11>> gen;

    return gen.fill();
}
