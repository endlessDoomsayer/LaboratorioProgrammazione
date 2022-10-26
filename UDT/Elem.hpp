#pragma once
#include <iostream>

class Elem
{
public:
	Elem(std::string name, Elem* prec = nullptr, Elem* succ = nullptr);
	~Elem();

	Elem* insSucc(Elem* n);
	Elem* insPrec(Elem* n);
	std::string erase();
	Elem* find(const std::string& name);
	Elem* next() const { return this->succ; }
	Elem* prev() const {return this->prec; }
	Elem* advance(int n) const;

	static Elem* find(Elem* elem, const std::string& name);

	std::string getName() const { return this->name; }

	

private:
	std::string name;
	Elem* prec;
	Elem* succ;
	
	Elem* removeNext(Elem* elem);
	Elem* removePrev(Elem* elem);
};

std::ostream& operator<<(std::ostream& os, const Elem& el);
