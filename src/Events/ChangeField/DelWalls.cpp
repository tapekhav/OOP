#include "DelWalls.h"

DelWalls::DelWalls(Field *field) {
    this->field = field;
}

void DelWalls::execute() {
    field->delete_walls();
}
