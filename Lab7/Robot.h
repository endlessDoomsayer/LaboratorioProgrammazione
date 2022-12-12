#ifndef Robot_H
#define Robot_H

#include "Maze.h"


class Robot
{
protected:
	Tile pos;
public:
	Robot(Tile tile) : pos{ tile } { }
	virtual void move(Maze& maze) = 0;
	Tile getPos() { return pos; }
};

#endif