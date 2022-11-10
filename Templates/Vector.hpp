#include "Vector.h"
template<typename T>
Vector<T>::Vector(std::initializer_list<T> list)
	:size{list.size()}, elems{new T[size]}
{
	std::copy(list.begin(), list.end(), elems);
}

template<typename T>
Vector<T>::~Vector()
{
	size = 0;
	delete[] elems;
}

template<typename T>
T Vector<T>::at(int id)
{
	return elems[id];
}

template<typename T>
void Vector<T>::set(T el, int id)
{
	elems[id] = el;
}

template<typename T>
T find_max(T e1, T e2) {
	return e1 > e2 ? e1 : e2;
}