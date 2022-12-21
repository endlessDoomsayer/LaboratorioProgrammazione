#include "Maze.h"

void Maze::readMapfromFile()
{
	std::ifstream ifs(this->filename);

	map = new Tile*[HEIGHT];

	for(int y=0; y < HEIGHT; y++){

		map[y] = new Tile[WIDTH];

		std::string line = "";
		std::getline(ifs, line, '\n');

		for (int x = 0; x < line.size(); x++) {
			bool solid = false;
			if (line.at(x) == '*') solid = true;
			map[y][x] = Tile(Pos(x, y), Elem(line.at(x), solid));

			if (line.at(x) == 'S') robotTileId = &map[y][x];
			if (line.at(x) == 'E') exitTileIds.push_back(&map[y][x]);
		}
	}
}

Maze::Maze(std::string filename)
	:	filename{filename}
{
	readMapfromFile();
}

Pos Maze::setRobotTile(Pos npos, Elem trail)
{
	robotTileId->setElem(trail);

	map[npos.getY()][npos.getX()] = Tile(npos, ROBOT_ELEM);

	robotTileId = &map[npos.getY()][npos.getX()];

	return robotTileId->getPos();
}

Direction Maze::calcDirByAdiacTile(Tile* adiacent)
{
	if (robotTileId->getY() - 1 >= 0)
		if (&map[robotTileId->getY() - 1][robotTileId->getX()] == adiacent) return Value::up;
	if(robotTileId->getY()+1 < HEIGHT)
		if (&map[robotTileId->getY() + 1][robotTileId->getX()] == adiacent) return Value::down;
	if (robotTileId->getX() - 1 >= 0)
		if (&map[robotTileId->getY()][robotTileId->getX()-1] == adiacent) return Value::up;
	if (robotTileId->getX() + 1 < WIDTH)
		if (&map[robotTileId->getY()][robotTileId->getX()+1] == adiacent) return Value::down;

	return Value::up;
}

const std::vector<Tile*> Maze::getSurroundingEmptyTiles(const Pos pos) const
{
	std::vector<Tile*> v(0);

	if (pos.getY() - 1 >= 0 && map[pos.getY() - 1][pos.getX()].isSolid()) v.push_back(&map[pos.getY() - 1][pos.getX()]);
	if (pos.getY() + 1 < HEIGHT && map[pos.getY() + 1][pos.getX()].isSolid()) v.push_back(&map[pos.getY() + 1][pos.getX()]);
	if (pos.getX() - 1 >= 0 && map[pos.getY()][pos.getX()-1].isSolid()) v.push_back(&map[pos.getY()][pos.getX() - 1]);
	if (pos.getX() + 1 < WIDTH && map[pos.getY()][pos.getX()+1].isSolid()) v.push_back(&map[pos.getY()][pos.getX() + 1]);

	return v;
}

const bool Maze::isResolved() const
{
	for (Tile* exit : exitTileIds) {
		if (robotTileId->getPos() == exit->getPos()) return true;
	}

	return false;
}

std::ostream& operator<<(std::ostream& os, Maze& maze)
{
	Tile** map = maze.getMap();
	for (int y = 0; y < Maze::HEIGHT; y++) {
		for (int x = 0; x < Maze::WIDTH; x++)
			os << map[y][x];
		os << std::endl;
	}

	return os;
}