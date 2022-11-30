#ifndef VectorT_Hpp
#define VectorT_Hpp

#include "VectorT.h"

template<typename T>
void VectorT<T>::resize()
{
	sz_p *= RESIZE_FACTOR;
	T* elems = new T[sz_p];
	std::copy(&this->elems[0], &this->elems[sz_v - 1], elems);

	delete[] this->elems;

	this->elems = elems;
}

template <typename T>
VectorT<T>::VectorT(T* elems, size_t size)
	: sz_v{size}, sz_p{sz_v*2}, elems{new T[sz_p]}
{
	for (int i = 0; i < sz_v; i++) {
		this->elems[i] = elems[i];
	}
}

template <typename T>
VectorT<T>::VectorT(std::initializer_list<T> list)
	: sz_v{list.size()}, sz_p{sz_v*2}, elems{new T[sz_p]}
{
	std::copy(list.begin(), list.end(), elems);
}

template<typename T>
VectorT<T>::VectorT()
	: sz_v{0}, sz_p{5}, elems{new T[sz_p]}
{
}

template<typename T>
T VectorT<T>::push_back(T t)
{
	if (sz_v == sz_p) {
		resize();
	}
	
	elems[sz_v] = t;
	sz_v++;

	return t;
}

template<typename T>
T VectorT<T>::pop_back()
{
	if (sz_v == 0) throw std::out_of_range("POP BACK ON AN EMPTY VECTOR\n");

	T elem = elems[sz_v - 1];
	sz_v--;

	return elem;
}

template<typename T>
T& VectorT<T>::at(const size_t id)
{
	if (id < sz_v) return elems[id];
	throw std::out_of_range("ID");
}

template<typename T>
T VectorT<T>::at(const size_t id) const
{
	if (id < sz_v) return elems[id];
	throw std::out_of_range("ID: " + id);
}

template<typename T>
T& VectorT<T>::operator[](const size_t id)
{
	return elems[id];
}

template<typename T>
T VectorT<T>::operator[](const size_t id) const
{
	return elems[id];
}


template <typename T>
std::ostream& operator<<(std::ostream& os, VectorT<T> v) {
	for (int i = 0; i < v.getSize(); i++) {
		os << v[i];
	}

	return os;
}

#endif