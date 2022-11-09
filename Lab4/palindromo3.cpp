#include <iostream>

bool is_palindrome(const char* first, const char* last);

int main3(void) {

	char c[] = "emme";

	std::cout << is_palindrome(&c[0], &c[3]) << std::endl;;

	return 0;
}

bool is_palindrome(const char* first, const char* last)
{
	int i = 0, j = static_cast<int>(last - first);

	while (i < j) {
		if (first[i] != last[-i]) return false;
		i++;
		j--;
	}

}
