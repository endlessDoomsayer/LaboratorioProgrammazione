#include <iostream>

bool is_palindrome(const std::string& s);

int main1(void) {

	std::string s = "aassaa";

	std::cout << is_palindrome(s) << std::endl;

	return 0;
}

bool is_palindrome(const std::string& s)
{
	int i = 0, j = s.size() - 1;

	while (i < j) {
		if (s.at(i) != s.at(j)) return false;
		i++;
		j--;
	}

	return true;
}
