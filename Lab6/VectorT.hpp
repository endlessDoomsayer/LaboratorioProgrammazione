#ifndef VectorT_Hpp
#define VectorT_Hpp

#include "VectorT.h"

template<typename T>
void VectorT<T>::reserve(size_t size)
{
	if (sz_p < size) {
		sz_p = size;
		T* elems = new T[size];
		std::copy(this->elems, &this->elems[sz_v], elems);
		delete[] this->elems;
		this->elems = elems;
	}
}

template <typename T>
VectorT<T>::VectorT(T* elems, size_t size)
	: sz_v{size}, sz_p{size}, elems{new T[size]}
{
	std::copy(elems, &elems[size], this->elems);
}

template <typename T>
VectorT<T>::VectorT(std::initializer_list<T> list)
	: sz_v{list.size()}, sz_p{list.size()}, elems{new T[list.size()]}
{
	std::copy(list.begin(), list.end(), elems);
}

template<typename T>
VectorT<T>::VectorT(size_t size)
	: sz_v{0}, sz_p{size}, elems{new T[size]}
{
}

template<typename T>
VectorT<T>::VectorT(const VectorT<T>& v)
	: sz_v{v.sz_v}, sz_p{v.sz_p}, elems{new T[v.sz_p]}
{
	std::cout << " copy constructor\n";
	std::copy(v.elems, &v.elems[v.sz_v], elems);
}

template<typename T>
VectorT<T>::VectorT(VectorT<T>&& v)
	: sz_v{ v.sz_v }, sz_p{ v.sz_p }, elems{ v.elems }
{
	std::cout << " move constructor\n";
	v.elems = nullptr;
	v.sz_v = 0;
	v.sz_p = 0;
}

template<typename T>
T VectorT<T>::push_back(T t)
{
	if (sz_v == sz_p) {
		reserve(sz_p * 2);
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
T VectorT<T>::operator[] (const size_t id) const
{
	return elems[id];
}

template<typename T>
T& VectorT<T>::operator=(const VectorT<T>& v) {
	std::cout << " copy assignment\n";
	delete[] elems;
	sz_v = v.sz_v;
	sz_p = v.sz_p;

	elems = new T[v.size_p];
	std::copy(&v[0], &v[v.sz_v], elems);

	return *this;
}

template<typename T>
T& VectorT<T>::operator=(VectorT<T>&& v) {
	std::cout << " move assignment\n";
	delete[] elems;
	sz_v = v.sz_v;
	sz_p = v.sz_p;

	elems = v.elems;
	
	v.elems = nullptr;
	v.sz_v = 0;
	v.sz_p = 0;

	return *this;
}


template <typename T>
std::ostream& operator<<(std::ostream& os, VectorT<T> v) {
	for (int i = 0; i < v.getSize(); i++) {
		os << v[i];
	}

	return os;
}

#endif