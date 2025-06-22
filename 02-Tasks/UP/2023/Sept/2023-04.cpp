#include <iostream>

void main() {
	unsigned int x = 0x11335577;
	unsigned char* ptr = (unsigned char*)&x;
	++*ptr;
	++*(ptr + 1);
	++ptr[2];
	++3[ptr];
	std::cout << std::hex << "0x" << x;
}

// Additional personal question: Does endiness matter?