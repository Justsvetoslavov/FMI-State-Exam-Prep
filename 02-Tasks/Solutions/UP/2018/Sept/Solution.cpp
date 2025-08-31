#include <string>
#include <iostream>
#include <vector>

#include <sstream>

const int m = 10;
const int n = 10;

bool isSorted(char arr[n][101], size_t cols) {
	for (size_t i = 0; i < cols - 1; i++) {
		if (strcmp(arr[i], arr[i + 1]) > 0) {
			return false;
		}
	}
	return true;
}

void revealPassword(char arr[m][n][101], size_t rows, size_t cols) {
	for (size_t i = 0; i < rows; i++) {
		if (!isSorted(arr[i], cols)) {
			continue;
		}

		size_t index = (cols - 1) / 2;
		std::stringstream ss(arr[i][index]);
		char buffer[101];
		while (!ss.eof()) {
			ss.getline(buffer, 100, ' ');
			std::cout << strlen(buffer) << " ";
		}
	}
}

int main() {
	char arr[m][n][101] =
	{
		{"na", "nblge brah", "nc"},
		{"no", "alge brah", "no"},
		{"nd", "nealge brah", "ng"},
	};
	revealPassword(arr, 3, 3);
}
