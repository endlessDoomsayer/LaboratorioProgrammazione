#include <iostream>
#include "Vettore.hpp"

int main(void) {

	std::cout << "Vettore v1 {1,2.1,3,4.6}" << std::endl;
	Vettore v1 {1,2.1,3,4.6};
	//stampa v1
	for(int i = 0; i < 4; i++)
		std::cout << " " << v1[i];

	std::cout << "declaring v2: ";
	Vettore v2(4);
	
	std::cout << "accessing v1[2] = " << v1[2] << std::endl;
	
	std::cout << "assignment: v2[0] = v1[0]: ";
	v2[0] = v1[0];

	std::cout << "v2[0] = " << v2[0] << std::endl;

	std::cout << "assignment: v3 = v1" << std::endl;
	Vettore v3 = v1;

	std::cout << "v2 = v3" << std::endl;
	v2 = v3;
	
	return 0;
}