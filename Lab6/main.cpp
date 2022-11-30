#include "VectorT.h"
#include <iostream>

int main() {

	VectorT<int> v{ 1,2,3,4,5 };

	std::cout << "size: " << v.getSize() << ", elements: " << v;
	
	

	v.push_back(1);

	std::cout << v;
	/*v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(100);
	v.push_back(200);*/

	return 0;
}