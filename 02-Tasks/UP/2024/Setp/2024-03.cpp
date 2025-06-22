#include <iostream>

void main() {
	int total = 0;
	for (int i = 2; i <= 10; ) {
		if (i % 3 == 0) {
			total = total + i;
		}
		i += 2;
	}
	std::cout << total << std::endl;
}

