#ifndef Maze_H
#define Maze_H

#include <fstream>
#include <string>
#include <vector>

#include "Tile.h"
#include "Direction.h"

class Maze
{
private:
	const Elem ROBOT_ELEM = Elem('S', 1);

	std::string filename;

	Tile** map;

	Tile* robotTileId;
	std::vector<Tile*> exitTileIds;

	void readMapfromFile();

public:
	static const int WIDTH = 9, HEIGHT = 9;

	Maze(std::string filename);
	
	Tile** getMap() { return map; }
	const Tile& getRobotTileId() const { return *robotTileId; }
	Pos setRobotTile(Pos npos, Elem oldElem);
	const std::vector<Tile*>& getExitTileIds() const { return exitTileIds; }
	Direction calcDirByAdiacTile(Tile* adiacent);
	const std::vector<Tile*> getSurroundingEmptyTiles(const Pos pos) const;

	const bool isResolved() const;
};

std::ostream& operator<<(std::ostream& os, Maze& maze);


#endif