#ifndef Maze_H
#define Maze_H

#include <fstream>
#include <string>

#include "Tile.h"

class Maze
{
private:
	std::string filename;
	const int HEIGHT, WIDTH;
	Tile<char>** map;

	const int initHEIGHT();
	const int initWIDTH();
	void readMapfromFile();

public:
	Maze(std::string filename);

	const int getHeight() { return HEIGHT; }
	const int getWidth() { return WIDTH; }
	const Tile<char> getTile(Position p);
	
};

std::ostream& operator<<(std::ostream& os, Maze maze);


#endif