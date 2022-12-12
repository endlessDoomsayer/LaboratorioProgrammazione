#include "Maze.h"
#include "RandomRobot.h"
#include "RightHandRobot.h"
#include <iostream>
#include <chrono>
#include <thread>

int main(void) {

	Maze maze = Maze("maze.txt");
	
	std::cout << maze;

	Robot* robot = new RightHandRobot(maze.getRobotPos());

	while (!maze.isResolved()) {
		
		std::this_thread::sleep_for(std::chrono::milliseconds(250));

		//update
		robot->move(maze);

		//draw
		system("CLS");
		std::cout << maze;
	}

	return 0;
}