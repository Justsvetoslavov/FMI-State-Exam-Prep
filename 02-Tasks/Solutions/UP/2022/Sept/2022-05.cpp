int main()
{
	char arr[3][3] = { 'a', 'b', 'c',
					   'd', 'e', 'f',
					   'g', 'h', 'i' };
	for (int i = 0; i < 3; ++i)
		std::cout << arr[2 - i][i]; // arr[2][0], arr[1][1], arr[0][2] -> gec
}