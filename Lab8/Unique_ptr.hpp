#ifndef Unique_ptr_HPP
#define Unique_ptr_HPP

#include "Unique_ptr.h"

template<typename T>
Unique_ptr<T>::~Unique_ptr()
{
	reset();
}

template <typename T>
void Unique_ptr<T>::reset(T* elem) {
	
	delete this->elem;
	this->elem = elem;
}

template<typename T>
T* Unique_ptr<T>::release()
{
	T* elem = this->elem;
	this->elem = nullptr;
	return elem;
}

#endif
