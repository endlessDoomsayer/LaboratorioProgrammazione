#ifndef Tile_H
#define Tile_H

#include "Elem.h"
#include "Pos.h"

#include <ostream>

class Tile : public Elem, public Pos
{
private:

public:
	Tile(Pos pos = Pos(0,0), Elem elem = Elem(' ', 0)) : Pos(pos), Elem(elem) {}

	Pos getPos() const { return Pos(this->x, this->y); }
	Elem getElem() const { return Elem(this->val, this->solid); }

	void setPos(Pos pos) { this->x = pos.getX(); this->y = pos.getY(); }
	void setElem(Elem elem) { this->val = elem.getVal(); this->solid = elem.isSolid(); }
};

std::ostream& operator<<(std::ostream& os, const Tile& tile);

#endif