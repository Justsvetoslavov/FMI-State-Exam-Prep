// Да се попълнят празните места в дефинициите на функциите така, че isOdd да връща истина тогава и само тогава,
// когато подаденото `и число е нечетно, а isEven — когато то е четно.

bool isEven(unsigned int);

bool isOdd(unsigned int n) {
	if (n == 0) return false;
	if (n == 1) return true;
	return isEven(n % 2);
}

bool isEven(unsigned int n) {
	if (n == 0) return true;
	if (n == 1) return false;
	return isOdd(n % 2);
}
