#ifndef RandomRobot_H
#define RandomRobot_H

#include "Robot.h"

class RandomRobot : public Robot
{
private:

public:
    RandomRobot(Tile tile) : Robot(tile) { std::srand(std::time(NULL)); }

    void move(Maze& maze);
};


#endif