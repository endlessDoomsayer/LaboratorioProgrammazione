#include "Pos.h"

bool Pos::operator==(Pos pos)
{
    return (this->x == pos.x && this->y == pos.y);
}

bool Pos::operator!=(Pos pos)
{
    return !(*this == pos);
}
