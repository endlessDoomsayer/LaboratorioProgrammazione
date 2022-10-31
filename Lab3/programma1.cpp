#include <iostream>
#include "programmi.h"


void Prog1::print(int* v, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

void Prog1::f() {
	int v[10]{ 0,1,2,3,4,5,6,7,8,9 };

	int* p { &v[3] };

	for (int i{ 0 }; i < 10; i++) {
		p[i - 3] = i - 3;
	}

	print(v, 10);
}

void Prog1::f_illegal() {
	int v[10]{ 0,1,2,3,4,5,6,7,8,9 };

	int* p { &v[3] };

	for (int i = 0; i < 10; i++) {
		p[i] = i;
	}

	print(v, 10);
}

void Prog1::exec() {

	f();

	//f_illegal();

}
