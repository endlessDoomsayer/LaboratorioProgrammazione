#ifndef Vector_h
#define Vector_h

#include <initializer_list>
#include <algorithm>

template<typename T>
class Vector
{
private:
	size_t size;
	T* elems;

public:
	Vector(std::initializer_list<T>);
	~Vector();

	T at(int id);
	void set(T el, int id);
};

template<typename T>
T find_max(T e1, T e2);

#include "Vector.hpp"

#endif