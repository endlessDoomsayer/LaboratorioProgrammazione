#include "Maze.h"
#include <iostream>

int main(void) {

	Maze maze = Maze("maze.txt");
	
	std::cout << maze;
	return 0;
}