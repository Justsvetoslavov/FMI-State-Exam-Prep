#include <iostream>

void main() {
	int var = 0;
	while (var++ < 5)
		std::cout << var;
	var = 0;
	do {
		std::cout << var;
	} while (++var < 5);
}
