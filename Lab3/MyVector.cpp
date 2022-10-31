#include "MyVector.hpp"

MyVector::MyVector(int size)
{
	if (size > 0) {
		this->size = size;
		this->v = new double[this->size] {};
	}
	else throw SizeException("size error!");
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

void MyVector::safe_set(int id, double val)
{
	if (id < this->size && id >= 0) this->v[id] = val;
}

double MyVector::safe_get(int id)
{
	if (id < this->size && id >= 0) return this->v[id];
	return 0;
}
