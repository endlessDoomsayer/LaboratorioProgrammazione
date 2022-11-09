#include "Link.h"

Link::Link(const std::string& v, Link* prev, Link* succ)
	: value{v}, prec{prev}, succ{succ}
{
}

Link::~Link()
{
	Link* curr = this;

	while (curr->succ) { //estremo dx
		curr = curr->succ;
	}

	while (curr != this) {
		curr = curr->prec;
		delete curr->succ;
	}
	//sono tornato a this

	while (curr->prec) { //estremo sx
		curr = curr->prec;
	}

	while (curr != this) {
		curr = curr->succ;
		delete curr->prec;
	}
}

Link* Link::insert(Link* n)
{
	if (n) {
		n->prec = this->prec;
		n->succ = this;
		if(this->prec)	this->prec->succ = n;
		this->prec = n;
	}

	return n;
}

Link* Link::add(Link* n)
{
	if (n) {
		n->succ = this->succ;
		n->prec = this;
		if(this->succ)	this->succ->prec = n;
		this->succ = n;
	}

	return n;
}

Link* Link::erase()
{
	if (this->prec && this->succ) {
		this->prec->succ = this->succ;
		this->succ->prec = this->prec;
	}

	return this;
}

Link* Link::find(std::string v)
{
	Link* curr = this;

	while (curr) { //dx
		if (curr->value == v) return curr;
		curr = curr->succ;
	}

	curr = this;
	while (curr) { //sx
		if (curr->value == v) return curr;
		curr = curr->prec;
	}

	return nullptr;
}

Link* Link::advance(int n)
{
	Link* curr = this;
	int i = 0;
	if (n > 0) { //avanzo
		while (i < n && curr->succ) {
			curr = curr->succ;
			i++;
		}
	}
	else { //arretro
		while (i > n && curr->prec) {
			curr = curr->prec;
			i--;
		}
	}
	return curr;
}

void Link::print_all()
{
	Link* curr = this;

	while (curr->prec) {
		curr = curr->prec;
	}

	while (curr) {
		std::cout << curr->value << " ";
		curr = curr->succ;
	}
	std::cout << std::endl;
}

Link* Link::push_back(Link* n)
{
	Link* curr = this;

	while (curr->succ) {
		curr = curr->succ;
	}

	n->prec = curr;
	curr->succ = n;

	return n;
}

Link* Link::push_front(Link* n)
{
	Link* curr = this;

	while (curr->prec) {
		curr = curr->prec;
	}

	n->succ = curr;
	curr->prec = n;

	return n;
}

Link* Link::pop_back()
{
	Link* curr = this;

	while (curr->succ) {
		curr = curr->succ;
	}

	return curr->erase();
}

Link* Link::pop_front()
{
	Link* curr = this;

	while (curr->prec) {
		curr = curr->prec;
	}

	return curr->erase();
}
