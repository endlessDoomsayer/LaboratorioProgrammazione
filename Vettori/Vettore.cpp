#include "Vettore.hpp"
#include <iostream>

Vettore::Vettore(std::initializer_list<double> list)
	: sz{list.size()}, elems {new double[sz]}
{
	std::cout << "constructor with initializer list" << std::endl;
	std::copy(list.begin(), list.end(), elems);
}

Vettore::Vettore(size_t s)
{
	std::cout << "uninitialized constructor" << std::endl;
	this->sz = s;
	this->elems = new double[s];
}

Vettore::Vettore(Vettore& v)
	: sz{v.sz}, elems{new double[sz]}
{
	std::cout << "copy constructor" << std::endl;

	std::copy(v.elems, v.elems+this->sz, this->elems);
}

Vettore::Vettore(Vettore&& v)
	: sz{v.sz}, elems{v.elems}
{
	std::cout << "move constructor" << std::endl;

	v.sz = 0;
	v.elems = nullptr;
}

Vettore::~Vettore()
{
	std::cout << "destructor" << std::endl;

	delete[] this->elems;
}

Vettore& Vettore::operator=(const Vettore& v)
{
	std::cout << "deep copy" << std::endl;

	double* p = new double[v.sz];
	std::copy(v.elems, v.elems + sz, p);
	delete[] this->elems;

	this->elems = p;
	this->sz = v.sz;

	return *this;
}

Vettore& Vettore::operator=(Vettore&& v)
{
	std::cout << "move assignment" << std::endl;

	delete[] this->elems;
	this->elems = v.elems;
	this->sz = v.sz;
	v.sz = 0;
	v.elems = nullptr;

	return *this;
}

/*double& Vettore::operator[](int n)
{
	if(n < this->sz) return elems[n];
	throw OutOfBoundsException(std::to_string(n));
}*/

double& Vettore::operator[](int n) {
	return elems[n];
}

/*double Vettore::operator[](int n) const
{
	if (n < this->sz) return elems[n];
	throw OutOfBoundsException(std::to_string(n));
}*/

double Vettore::operator[](int n) const
{
	return elems[n];
}

std::ostream& operator<<(std::ostream& os, Vettore& v)
{
	for (int i = 0; i < v.sz; i++) {
		os << v[i];
	}

	return os;
}

bool Vettore::set(unsigned int id, double val)
{
	if (id < this->sz - 1) {
		elems[id] = val;
		return true;
	}
	throw OutOfBoundsException(std::to_string(id));
	return false;
}

double Vettore::get(unsigned int id) const
{
	if (id < this->sz) return elems[id];
	throw OutOfBoundsException(std::to_string(id));
	return 0;
}

OutOfBoundsException::OutOfBoundsException(std::string t)
	:message{t}
{

}

std::string OutOfBoundsException::printError(std::string t)
{
	return this->message;
}
