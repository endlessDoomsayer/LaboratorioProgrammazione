#pragma once
#include <exception>
#include <string>
#include <iostream>

class MyVector
{
private:
	size_t size;
	double* v;
public:
	MyVector(std::initializer_list<double> list);
	MyVector(size_t size);
	//copy constructor
	MyVector(MyVector& v);
	//move constructor
	MyVector(MyVector&& v);
	
	~MyVector();

	double& operator[](int id);
	double operator[](int id) const;

	//copy assignment
	MyVector& operator=(const MyVector& v);
	//move assignment
	MyVector& operator=(MyVector&& v);

	void safe_set(int id, double val);
	double safe_get(int id);
};

class SizeException : std::exception {
private:
	std::string message;
public:
	SizeException(std::string s)
		: message{ s }
	{}

	void print() { std::cout << this->message; }
};