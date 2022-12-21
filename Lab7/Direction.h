#ifndef Direction_H
#define Direction_H

enum Value
{
	up = 0,
	left,
	down,
	right
};

inline Value& operator++(Value& v) {
	v = static_cast<Value>((v + 1) % (Value::right + 1));
	return v;
}
inline Value operator++(Value& v, int) {
	Value nv = v;
	++v;
	return nv;
}

inline Value& operator--(Value& v) {
	int r = (int)v - 1;
	if (r < 0) r = Value::right;
	v = static_cast<Value>(r);
	return v;
}
inline Value operator--(Value& v, int) {
	Value nv = v;
	--v;
	return nv;
}

class Direction
{

public:
	Direction(Value v) : value{ v } {}

	void turnRight() { this->value++; }
	void turnLeft() { this->value++; }
	void pointTo(Value v) { this->value = v; }
	bool operator==(Direction d) { return d.value == this->value; }
	bool operator!=(Direction d) { return d.value != this->value; }

	Value getValue() { return value; }

private:
	Value value;
};

#endif