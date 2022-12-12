#include "RightHandRobot.h"

void RightHandRobot::turnLeft()
{
	dir = Direction((dir + 1) % (down+1));
}

void RightHandRobot::turnRight()
{
	dir = Direction((dir - 1) % (down + 1));
}

const Tile RightHandRobot::facing()
{
	Tile t = pos;

	switch (dir) {
	case right:
		t.setX(pos.getX() + 1);
		break;
	case up:
		t.setY(pos.getY() - 1);
		break;
	case left:
		t.setX(pos.getX() - 1);
		break;
	case down:
		t.setY(pos.getY() + 1);
		break;
	}

	return t;
}

const Tile RightHandRobot::to_right()
{
	Tile t = pos;

	switch (dir) {
	case right:
		t.setY(pos.getY() + 1);
		break;
	case up:
		t.setX(pos.getX() + 1);
		break;
	case left:
		t.setY(pos.getY() - 1);
		break;
	case down:
		t.setX(pos.getX() - 1);
		break;
	}

	return t;
}

void RightHandRobot::move(Maze& maze)
{
	Tile to;

	if (maze.getTile(to_right()).getValue() == '*') {
		while (maze.getTile(facing()).getValue() == '*') {
			turnLeft();
		}

		to = maze.getTile(facing());
	}
	else {
		to = maze.getTile(to_right());
		turnRight();
	}

	maze.move(Tile(pos.getX(), pos.getY(), '.'), Tile(to.getX(), to.getY(), 'S'));
	pos.setPos(to.getX(), to.getY());
	maze.setRobotPos(pos);
}
