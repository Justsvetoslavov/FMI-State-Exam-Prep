#include <iostream>


size_t myStrlen(const char* string) {
	if (!string) {
		return 0;
	}
	size_t size = 0;
	while (*string) {
		size++;
		string++;
	}
	return size;
}

void print_backwards(const char* begin, const char* end) {
	if (!begin || !end) {
		return;
	}
	if (begin >= end) {
		return;
	}

	// recursive
	if (*begin <= 32) {
		print_backwards(begin + 1, end);
		return;
	}

	const char* endOfWord = begin;
	while (endOfWord < end && (*endOfWord) > 32) {
		endOfWord++;
	}

	print_backwards(endOfWord, end);

	if (endOfWord != end) {
		std::cout << ' ';
	}
	while (begin < endOfWord) {
		std::cout << *begin;
		begin++;
	}
}

void print_backwards(const char* string) {
	const char* end = string + myStrlen(string);
	print_backwards(string, end);
}

int main() {
	print_backwards("\tI\tneed a break!"); // "break! a need I"
}
