#include "Tile.h"


Tile::Tile(int x, int y, char value)
	: x{x}, y{y}, value{value}
{
}

bool Tile::operator==(const Tile& t)
{
	if (this->x == t.x && this->y == t.y && this->value == t.value) return true;
	return false;
}

bool Tile::operator!=(const Tile& t)
{
	if (*this == t) return false;
	return true;
}

/*Tile& Tile::operator=(const Tile& t)
{
	this->x = t.x;
	this->y = t.y;
	this->value = t.value;

	return *this;
}*/

std::ostream& operator<<(std::ostream& os, Tile tile)
{
	os << tile.getValue();
	return os;
}
