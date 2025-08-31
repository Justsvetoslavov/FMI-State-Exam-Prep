// Да се довърши кодът на рекурсивните функции, така че f да проверява дали символният низ, сочен от word, се съдържа като подниз в text.
// Заопределеност считаме, че празният низ се съдържа във всеки друг.

bool g(const char* text, const char* word) {
	if (!*word) return true;
	if (!*text) return _____________;
	if (*word != *text) return false;
	return g(_____________, _____________);
}

bool f(const char* text, const char* word) {
	if (!*word) return _____________;
	if (!*text) return false;
	return g(_____________, _____________) ||
		f(_____________, _____________);
}