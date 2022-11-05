#include "MyVector.hpp"

MyVector::MyVector(std::initializer_list<double> list)
	: size{ list.size() }
{
	this->v = new double[size];

	std::cout << "constructor with initializer list" << std::endl;
	std::copy(list.begin(), list.end(), v);

	std::cout << "size: " << this->size << std::endl;
}

MyVector::MyVector(size_t size)
{
	if (size > 0) {
		this->size = size;
		this->v = new double[this->size] {};
	}
	else throw SizeException("size error!");
}

MyVector::MyVector(MyVector& v)
	: size{ v.size }
{
	this->v = new double[size];
	std::cout << "copy constructor" << std::endl;

	std::copy(v.v, v.v + this->size, this->v);
}

MyVector::MyVector(MyVector&& v)
	: size{ v.size }, v{ v.v }
{
	std::cout << "move constructor" << std::endl;

	v.size = 0;
	v.v = nullptr;
}

MyVector::~MyVector()
{
	delete[] v;
}

double& MyVector::operator[](int id)
{
	return this->v[id];
}

double MyVector::operator[](int id) const
{
	return this->v[id];
}

MyVector& MyVector::operator=(const MyVector& v)
{
	std::cout << "deep copy" << std::endl;

	double* p = new double[v.size];
	std::copy(v.v, v.v + v.size, p);
	delete[] this->v;

	this->v = p;
	this->size = v.size;

	return *this;
}

MyVector& MyVector::operator=(MyVector&& v)
{
	std::cout << "move assignment" << std::endl;

	delete[] this->v;
	this->v = v.v;
	this->size = v.size;
	v.size = 0;
	v.v = nullptr;

	return *this;
}

void MyVector::safe_set(int id, double val)
{
	if (id < this->size && id >= 0) this->v[id] = val;
}

double MyVector::safe_get(int id)
{
	if (id < this->size && id >= 0) return this->v[id];
	return 0;
}
