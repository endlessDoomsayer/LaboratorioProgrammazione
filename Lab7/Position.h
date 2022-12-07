#ifndef Position_H
#define Position_H

class Position
{
private:
	int x, y;

public:
	Position(int x = 0, int y = 0) : x{ x }, y{ y } {}

	int getX() const { return x; }
	int getY() const { return y; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
};

#endif