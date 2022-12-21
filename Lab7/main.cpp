#include "RandomRobot.h"
#include <iostream>
#include <chrono>
#include <thread>

int main(void) {

	Maze maze = Maze("maze.txt");
	
	Robot* robot = new RandomRobot(maze.getRobotTileId());

	while (!maze.isResolved()) {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));

		system("CLS");
		std::cout << maze;

		robot->move(maze);
	}

	return 0;
}