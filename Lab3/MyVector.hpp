#pragma once
#include <exception>
#include <string>
#include <iostream>

class MyVector
{
private:
	int size;
	double* v;
public:
	MyVector(int size);
	~MyVector();

	double& operator[](int id);
	double operator[](int id) const;

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