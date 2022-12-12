#ifndef Maze_H
#define Maze_H

#include <fstream>
#include <string>
#include <vector>
#include "Tile.h"
#include <iostream>

class Maze
{
private:
	std::string filename;
	const int HEIGHT, WIDTH;
	Tile** map;
	Tile robotPos;
	std::vector<Tile> exits;

	const int initHEIGHT();
	const int initWIDTH();
	void readMapfromFile();

public:
	Maze(std::string filename);

	const int getHeight() { return HEIGHT; }
	const int getWidth() { return WIDTH; }
	const Tile getTile(int x, int y);
	const Tile getRobotPos() { return robotPos; }
	const std::vector<Tile> getSurroundingValidTiles(Tile curr);
	void setRobotPos(Tile pos) { this->robotPos = pos; }
	void move(Tile from, Tile to);

	bool isResolved();
};

std::ostream& operator<<(std::ostream& os, Maze maze);


#endif