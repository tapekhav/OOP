#include "SetWalls.h"

SetWalls::SetWalls(Field *field) {
    this->field = field;
}

void SetWalls::execute() {
    field->generate_walls();
}
