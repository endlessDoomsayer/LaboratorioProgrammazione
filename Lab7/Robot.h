#ifndef Robot_H
#define Robot_H

#include "Maze.h"
#include "Direction.h"

class Robot
{
protected:
	Tile tile;
	Direction dir;
	bool wall_found;

	Robot(Tile tile, Direction dir = up) : tile{ tile }, dir{ dir }, wall_found{ false } {}

public:
	virtual void start() = 0;
	virtual void move(Maze& maze) = 0;
	virtual Pos moveforward() = 0;
	Elem getTrailFromDir();
};

#endif