#include <iostream>

bool is_palindrome(const char s[], int length);

int main2(void) {

	char c[] = "emme";

	std::cout << is_palindrome(c, 4) << std::endl;

	return 0;
}

bool is_palindrome(const char s[], int length)
{
	int i = 0, j = length - 1;

	while (i < j) {
		if (s[i] != s[j]) return false;
		i++;
		j--;
	}
}
