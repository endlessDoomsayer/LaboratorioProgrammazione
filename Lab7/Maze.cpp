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

	this->map = new Tile<char>*[HEIGHT];

	for (int i = 0; i < HEIGHT; i++) {
		std::string line = "";
		std::getline(isfile, line, '\n');
		map[i] = new Tile<char>[WIDTH];
		for (int j = 0; j < WIDTH; j++) {
			map[i][j].setValue(line.at(j));
			map[i][j].setY(i);
			map[i][j].setX(j);
		}
	}
}

Maze::Maze(std::string filename)
	:	filename{filename}, HEIGHT{initHEIGHT()}, WIDTH{initWIDTH()}
{
	readMapfromFile();
}

const Tile<char> Maze::getTile(Position p)
{
	return map[p.getY()][p.getX()];
}

std::ostream& operator<<(std::ostream& os, Maze maze)
{
	for (int i = 0; i < maze.getHeight(); i++) {
		for (int j = 0; j < maze.getWidth(); j++)
			os << maze.getTile(Position(j,i)).getValue();
		os << "\n";
	}

	return os;
}
