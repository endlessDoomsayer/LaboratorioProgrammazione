#ifndef RightHandRobot_H
#define RightHandRobot_H

#include "Robot.h"

class RightHandRobot :
    public Robot
{
private:
    enum Direction {
        right = 0,
        up,
        left,
        down
    };

    Direction dir;

    void turnLeft();
    void turnRight();
    const Tile facing();
    const Tile to_right();

public:
    RightHandRobot(Tile tile) : Robot(tile) { std::srand(std::time(NULL)); dir = Direction(rand() % 4); }

    void move(Maze& maze);
};


#endif