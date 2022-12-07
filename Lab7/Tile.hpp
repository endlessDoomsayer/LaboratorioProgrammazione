#ifndef Tile_HPP
#define Tile_HPP
#include "Tile.h"

template<typename T>
Tile<T>::Tile(T value, int x, int y)
	: Position(x, y), value{ value }
{}


#endif