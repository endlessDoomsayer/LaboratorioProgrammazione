#ifndef Unique_ptr_H
#define Unique_ptr_H

template <typename T>
class Unique_ptr
{
private:
	T* elem;

public:
	Unique_ptr(T* elem) : elem{ elem } {}
	~Unique_ptr();
	Unique_ptr(Unique_ptr<T>& u) = delete;
	Unique_ptr(Unique_ptr<T>&& u) { this->elem = u.release(); }
	void reset(T* elem = nullptr);
	T* release();
	Unique_ptr& operator=(Unique_ptr & u) = delete;
	Unique_ptr& operator=(Unique_ptr&& u) { this->elem = u.release(); }

	T operator*() { return *this->elem; }
	T& operator->() { return this->elem; }
};

#include "Unique_ptr.hpp"

#endif
