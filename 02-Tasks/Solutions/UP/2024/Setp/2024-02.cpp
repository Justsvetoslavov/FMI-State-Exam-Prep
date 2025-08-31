#include <iostream>

void func(int& x, int* y, int z) {
	int a = 3;
	int b = 5;
	x = z - b;
	*y = 2 * z;
	z = x ? a + *y : 0;
}

void main() {
	int a = 2; int b = 4;
	func(b, &a, b);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
}

