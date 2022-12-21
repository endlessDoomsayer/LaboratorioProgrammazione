#include "Tile.h"

std::ostream& operator<<(std::ostream& os, const Tile& tile) {
	 os << tile.getVal();
	 return os;
}