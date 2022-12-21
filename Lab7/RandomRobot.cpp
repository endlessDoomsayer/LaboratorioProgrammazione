#include "RandomRobot.h"

void RandomRobot::start()
{
	srand(time(NULL));
}

void RandomRobot::move(Maze& maze)
{
	const std::vector<Tile*> surrEmptyTiles = maze.getSurroundingEmptyTiles(this->tile.getPos());

	if (!wall_found) if (surrEmptyTiles.size() < 4) wall_found = true;

	int choice = std::rand() % surrEmptyTiles.size();

	dir = maze.calcDirByAdiacTile(surrEmptyTiles[choice]);

	maze.setRobotTile(moveforward(), getTrailFromDir());

	this->tile = maze.getRobotTileId();
}

Pos RandomRobot::moveforward()
{
	switch (dir.getValue()) {
	case up:
		return Pos(tile.getX(), tile.getY() - 1);
	case down:
		return Pos(tile.getX(), tile.getY() + 1);
	case right:
		return Pos(tile.getX() + 1, tile.getY());
	case left: 
		return Pos(tile.getX() - 1, tile.getY());
	}

	return tile.getPos();
}
