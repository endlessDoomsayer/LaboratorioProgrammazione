#ifndef Tile_H
#define Tile_H
#include "Position.h"

template <typename T>
class Tile :
    public Position
{
private:
    T value;

public:
    Tile(T value, int x, int y);
    Tile() {}
    T getValue() const { return value; }
    void setValue(T value) { this->value = value; }
};

#include "Tile.hpp"

#endif