#ifndef Tile_H
#define Tile_H

#include <ostream>

class Tile
{
private:
	int x, y;
	char value;

public:
	Tile(int x = 0, int y = 0, char value = ' ');
	int getX() { return x; }
	int getY() { return y; }
	char getValue() { return value; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setPos(int x, int y) { this->x = x; this->y = y; }
	void setValue(char value) { this->value = value; }

	//Tile& operator=(const Tile& t);
};

std::ostream& operator<<(std::ostream& os, Tile tile);

#endif