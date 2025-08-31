#include <iostream>

void revStr(char* str, unsigned start, unsigned end) {
	if (start >= end) {
		return;
	}
	std::swap(str[start], str[end]);
	revStr(str, start+1, end-1);
}