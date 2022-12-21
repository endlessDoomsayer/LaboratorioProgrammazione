#ifndef RandomRobot_H
#define RandomRobot_H

#include "Robot.h"

class RandomRobot :
    public Robot
{
private:

public:
    RandomRobot(Tile tile, Direction dir = up) : Robot(tile, dir) {}

    void start();
    void move(Maze& maze);
    Pos moveforward();
};

#endif