#include <iostream>

void reverseMatrixRows(int** mat, int r, int c) {
	for (int i = 0; i < r / 2; ++i)
		for (int j = 0; j < c; ++j)
			std::swap(mat[i][j], mat[r-i-1][j]);
}

void reversematrixcols(int** mat, int r, int c) {
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c / 2; ++j)
			std::swap(mat[i][j], mat[i][c-j-1]);
}

void initialize(int** mat, int r, int c) {
	int index = 1;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			mat[i][j] = index++;
}

void print(int** mat, int r, int c) {
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j) std::cout << mat[i][j] << " ";
		std::cout << "\n";
	}
}

int main() {
	int** matrix = new int*[3];
	for (int i = 0; i < 3; ++i) {
		matrix[i] = new int[4];
	}

	initialize(matrix, 3, 4);
	//reverseMatrixRows(matrix, 3, 4);
	//reversematrixcols(matrix, 3, 4);;
	print(matrix, 3, 4);
}