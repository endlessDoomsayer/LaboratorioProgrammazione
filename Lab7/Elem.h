#ifndef Elem_H
#define Elem_H

class Elem
{
protected:
	bool solid;
	char val;
public:
	Elem(char val, bool solid) : val{ val }, solid{ solid } {}
	Elem(const Elem& elem) : val{ elem.val }, solid{ elem.solid } {}

	const char getVal() const { return val; }
	const bool isSolid() const { return solid; }
	void setVal(const char val) { this->val = val; }
	void setSolid(const bool solid) { this->solid = solid; }
};

#endif