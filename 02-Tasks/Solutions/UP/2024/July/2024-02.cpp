#include <iostream >

void main() {
	const size_t size = 3;
	int matrix[size][size] = {
	1, 2, 3,
	4, 5, 6,
	7, 8, 9
	};
	std::cout << matrix[1][2] << *matrix[2];
	std::cout << **matrix << *(*(matrix + 2) + 1);
}