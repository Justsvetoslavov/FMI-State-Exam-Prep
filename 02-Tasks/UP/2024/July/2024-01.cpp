#include <iostream >

void print(char* p) {
	if (*(p++)) print(++p);
	std::cout << *(--p);
}

void main() {
	char str[] = "012345";
    char* p = str;
	print(str);
}