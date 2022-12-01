#include "VectorT.h"
#include <iostream>

VectorT<char> genVectorChar() {
	VectorT<char> vettore{ 'a','b','c' };
	return vettore;
}

int main() {

	VectorT<char> v{ '1','2','3','4','5' };

	std::cout << "size: " << v.getSize() << ", elements: " << v << std::endl;

	v.push_back('1');
	v.push_back('2');
	v.push_back('3');
	v.push_back('4');
	v.push_back('5');
	v.push_back('1');
	v.push_back('1');

	VectorT<char> vnuovo = genVectorChar();

	std::cout << " elements: " << vnuovo;


	return 0;
}