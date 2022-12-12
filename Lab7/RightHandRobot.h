#ifndef RightHandRobot_H
#define RightHandRobot_H

#include "Robot.h"

class RightHandRobot :
    public Robot
{
private:

public:
    RightHandRobot(Tile tile) : Robot(tile) { std::srand(std::time(NULL)); }

    void move(Maze& maze);
};


#endif