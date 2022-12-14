#ifndef VETTORE
#define VETTORE
#include <initializer_list>
#include <algorithm>
#include <exception>
#include <string>
#include <iostream>

class Vettore
{
private:
	size_t sz;
	double* elems;

public:
	Vettore(std::initializer_list<double> list);
	Vettore(size_t s);
	//copy constructor
	Vettore(Vettore& v);
	//move constructor
	Vettore(Vettore&& v);
	~Vettore();

	//copy assignment
	Vettore& operator=(const Vettore& v);
	//move assignment
	Vettore& operator=(Vettore&& v);
	double& operator[](int n);
	double operator[](int n) const;

	friend std::ostream& operator<<(std::ostream& os, Vettore& v);


	bool set(unsigned int id, double val);
	double get(unsigned int id) const;
};

std::ostream& operator<<(std::ostream& os, Vettore& v);

class OutOfBoundsException : std::exception {
public:
	OutOfBoundsException(std::string t);

	std::string printError();

private:
	std::string message;

};

#endif