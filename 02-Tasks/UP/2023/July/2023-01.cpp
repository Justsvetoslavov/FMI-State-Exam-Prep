// Да се попълнят празните места в кода на функцията removeWhitespace така, че тя да премахва от непразния низ str всички whitespace символи.

bool isWhitespace(char c) {
	return c == ' ' || c == '\t' || c == '\r' || c == '\n';
}

const char* removeWhitespace(char* str) {
	size_t read = 0, write = 0;
	while (str[read]) {
		if (isWhitespace(str[read]))
			read++;
		else
			str[write++] = str[read++];;
	}
	str[write] = '\0';

	return str;
}