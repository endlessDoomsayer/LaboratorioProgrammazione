#include <iostream>
#include "Vector.h"

int main(void) {

	Vector<double> v = { 1,2,3.3,4.4,5.5 };

	std::cout << "v[2] = " << v.at(2) << std::endl;
	v.set(7, 2);
	std::cout << "v[2] set to 7 : " << v.at(2) << std::endl;
	std::cout << "max between 2 & 5 : " << find_max(2, 5);
}