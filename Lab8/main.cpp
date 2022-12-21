#include <iostream>
#include <vector>
#include "Unique_ptr.h"
#include <map>
#include <fstream>
#include <string>

int main(void) {
	/*
	std::unique_ptr<std::vector<int>> ptr = std::make_unique<std::vector<int>>(10);

	
	for (int i = 0; i < (*ptr).size(); i++) (*ptr)[i] = i;
	(*ptr).push_back(10);
	(*ptr).push_back(11);
	(*ptr).push_back(12);
	(*ptr).push_back(13);

	for(int i=0; i < (*ptr).size(); i++) std::cout << (*ptr)[i];
	*/

	//istogramma parole
	std::map<char, int> letters;

	std::string filename = "text.txt";
	std::ifstream ifs(filename);

	char c;
	while (ifs.get(c)) {
		++letters[c];
	}

	for (const auto& p : letters) std::cout << p.first << " : " << p.second << "\n";

	return 0;
}