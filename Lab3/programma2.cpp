#include <iostream>
#include "programmi.h"

namespace Prog2 {

	void print_array_length(double* v) {
		std::cout << "v size by function print: " << sizeof(v)/sizeof(double) << std::endl;
	}

	void exec() {
		constexpr int size { 12 };

		double v[size] {};

		std::cout << "v size: " << sizeof(v)/sizeof(double) << std::endl;

		print_array_length(v);

	}
}