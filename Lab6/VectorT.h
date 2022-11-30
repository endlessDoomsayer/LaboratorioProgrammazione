#ifndef VectorT_H
#define VectorT_H

#include <initializer_list>
#include <algorithm>
#include <stdexcept>

template <typename T>
class VectorT
{
private:
	static const unsigned int RESIZE_FACTOR = 2;
	size_t sz_v; //virtual size
	size_t sz_p; //physical size
	T* elems;

public:
	void resize();
	VectorT(T* elems, size_t size);
	VectorT(std::initializer_list<T> list);
	VectorT();


	T push_back(T t);
	T pop_back();

	size_t getSize() const { return this->sz_v; } //getSize returns virtual size
	T& at(const size_t id);
	T at(const size_t id) const;
	T& operator[] (const size_t id);
	T operator[] (const size_t id) const;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, VectorT<T> v);

#include "VectorT.hpp"

#endif