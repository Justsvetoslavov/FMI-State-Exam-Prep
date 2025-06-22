#include <iostream>

void print(char* str) {
	char* ptr = str;
	while (*ptr != '\0') {
		*ptr = *ptr + 1;
		ptr++;
	}
	std::cout << str;
}

void main() {
	char str[] = "ACE";
	print(str);
}

