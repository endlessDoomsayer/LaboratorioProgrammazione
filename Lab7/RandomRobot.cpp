#include "RandomRobot.h"

void RandomRobot::move(Maze& maze)
{
	std::vector<Tile> surroundings = maze.getSurroundingValidTiles(pos);

	int rng = std::rand() % surroundings.size();

	maze.move(Tile(pos.getX(), pos.getY(), '.'), Tile(surroundings[rng].getX(), surroundings[rng].getY(), 'S'));

	pos.setPos(surroundings[rng].getX(), surroundings[rng].getY());
	
	maze.setRobotPos(pos);
}
