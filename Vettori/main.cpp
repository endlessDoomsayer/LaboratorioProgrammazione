#include <iostream>
#include "Vettore.hpp"

int main(void) {

	std::cout << "Vettore v1 {1,2.1,3,4.6}" << std::endl;
	Vettore v1 {1,2.1,3,4.6};
	std::cout << "Vettore v2(4)" << std::endl;
	Vettore v2(4);

	std::cout << "v1[2] = " << v1[2] << std::endl;
	
	std::cout << "v2[0] = v1[0]" << std::endl;
	v2[0] = v1[0];

	std::cout << "v2[0] = " << v2[0] << std::endl;

	std::cout << "Vettore v3 = v1" << std::endl;
	Vettore v3 = v1;

	std::cout << "v2 = v3" << std::endl;
	v2 = v3;

	return 0;
}