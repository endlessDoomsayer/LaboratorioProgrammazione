#include <iostream>
#include "programmi.h"

namespace Prog3 {

	void print_reference(int& intero, double& virgola) {
		std::cout << "int: " << intero << " double: " << virgola << std::endl;
	}

	void print_pointer(int* intero, double* virgola) {
		std::cout << "int: " << *intero << " double: " << *virgola << std::endl;
	}

	void exec() {

		int intero{ 3 };
		double virgola{ 2.34 };

		print_reference(intero, virgola);
		print_pointer(&intero, &virgola);
	}
}