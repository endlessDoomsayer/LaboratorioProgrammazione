#ifndef Link_h
#define Link_h

#include <iostream>

class Link
{
private:
	std::string value;
	Link* prec;
	Link* succ;

public:
	Link(const std::string& v = "", Link* prev = nullptr, Link* succ = nullptr);
	~Link();

	Link* insert(Link* n); //inserimento precedente
	Link* add(Link* n); //inserimento successivo
	Link* erase(); //elimina this ma non lo dealloca
	Link* find(std::string v);
	Link* advance(int n);
	
	void print_all(); //print dal primo elemento
	Link* push_back(Link* n); //inserisce in coda
	Link* push_front(Link* n); //inserisce in testa
	Link* pop_back(); //elimina ultimo elem
	Link* pop_front(); //elimina primo elem

	std::string getValue() { return this->value; }
	Link* next() { return this->succ; }
	Link* prev() { return this->prec; }
};

#endif