#include "Maze.h"

const int Maze::initHEIGHT()
{
	std::ifstream isfile(this->filename);
	if (!isfile) return false;
	
	std::string line = "";
	int height = 0;
	while (std::getline(isfile, line)) {
		height++;
	}

	isfile.close();
	return height;
}

const int Maze::initWIDTH()
{
	if (HEIGHT == 0) return false;

	std::ifstream isfile(this->filename);
	if (!isfile) return false;

	std::string line = "";
	std::getline(isfile, line);

	isfile.close();
	return line.size();
}

void Maze::readMapfromFile()
{
	std::ifstream isfile(this->filename);

	this->map = new Tile*[HEIGHT];

	for (int y = 0; y < HEIGHT; y++) {
		std::string line = "";
		std::getline(isfile, line, '\n');
		map[y] = new Tile[WIDTH];
		for (int x = 0; x < WIDTH; x++) {
			map[y][x] = Tile(x,y,line.at(x));
			if (map[y][x].getValue() == 'S') robotPos = map[y][x];
			else if (map[y][x].getValue() == 'E') exits.push_back(map[y][x]);
		}
	}
}

Maze::Maze(std::string filename)
	:	filename{filename}, HEIGHT{initHEIGHT()}, WIDTH{initWIDTH()}
{
	readMapfromFile();
}

const Tile Maze::getTile(const Tile t)
{
	int y = t.getY();
	int x = t.getX();
	if (y < HEIGHT && x < WIDTH && y >= 0 && x >= 0)
		return map[y][x];
	else return '0';
}

const std::vector<Tile> Maze::getSurroundingValidTiles(Tile curr)
{
	std::vector<Tile> surroundings;

	int ofX = curr.getX();
	int ofY = curr.getY();

	if (ofY - 1 >= 0) if (map[ofY - 1][ofX].getValue() != '*') surroundings.push_back(map[ofY - 1][ofX]);
	if (ofY + 1 < HEIGHT) if (map[ofY + 1][ofX].getValue() != '*') surroundings.push_back(map[ofY + 1][ofX]);
	if (ofX - 1 >= 0) if (map[ofY][ofX - 1].getValue() != '*') surroundings.push_back(map[ofY][ofX - 1]);
	if (ofX + 1 < WIDTH) if (map[ofY][ofX + 1].getValue() != '*') surroundings.push_back(map[ofY][ofX + 1]);

	return surroundings;
}

void Maze::move(Tile from, Tile to)
{
	map[from.getY()][from.getX()].setValue(from.getValue());
	map[to.getY()][to.getX()].setValue(to.getValue());
}

Tile Maze::getRight(Tile pos)
{
	if (pos.getX() + 1 < WIDTH && map[pos.getY()][pos.getX()+1].getValue() != '*') return map[pos.getY()][pos.getX() + 1];
	return pos;
}

Tile Maze::getTop(Tile pos)
{
	if (pos.getY() - 1 >= 0 && map[pos.getY()-1][pos.getX()].getValue() != '*') return map[pos.getY()-1][pos.getX()];
	return pos;
}

Tile Maze::getLeft(Tile pos)
{
	if (pos.getX() - 1 >= 0 && map[pos.getY()][pos.getX() - 1].getValue() != '*') return map[pos.getY()][pos.getX() - 1];
	return pos;
}

Tile Maze::getBottom(Tile pos)
{
	if (pos.getY() + 1 < HEIGHT && map[pos.getY()+1][pos.getX()].getValue() != '*') return map[pos.getY() + 1][pos.getX()];
	return pos;
}

bool Maze::isResolved()
{
	for (int i = 0; i < exits.size(); i++)
		if (exits[i].getX() == robotPos.getX() && exits[i].getY() == robotPos.getY()) return true;

	return false;
}

std::ostream& operator<<(std::ostream& os, Maze maze)
{
	for (int y = 0; y < maze.getHeight(); y++) {
		for (int x = 0; x < maze.getWidth(); x++)
			os << maze.getTile(Tile(x,y));
		os << "\n";
	}

	return os;
}