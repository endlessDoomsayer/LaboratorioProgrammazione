#ifndef Pos_H
#define Pos_H

class Pos
{
protected:
	int x, y;

public:
	Pos(int x = 0, int y = 0) : x{ x }, y{ y } {}
	Pos(const Pos& pos) : x{ pos.x }, y{ pos.y } {}

	const int getX() const { return x; }
	const int getY() const { return y; }
	void setPos(const int x, const int y) { this->x = x; this->y = y; }
	void setX(const int x) { this->x = x; }
	void setY(const int y) { this->y = y; }

	bool operator==(Pos pos);
	bool operator!=(Pos pos);
};

#endif