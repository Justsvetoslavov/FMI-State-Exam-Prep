// Да се попълнят празните места в кода на функцията pass така, че функцията bubbleSort да сортира в нарастващ ред елементите на масива arr с размер size.
// Абстрахирайте се от това, че алгоритъмът, разписан по този начин, работи неефикасно.

void pass(int* arr, size_t size, bool& swappedAtLeastOnce)
{
	if (size <= 1)
		return;

	if (arr[0] > arr[1]) {
		std::swap(arr[0], arr[1]);
		swappedAtLeastOnce = true;
	}

	pass(arr + 1,
		size - 1,
		swappedAtLeastOnce);
}

void bubbleSort(int* arr, size_t size)
{
	bool swappedAtLeastOnce = false;
	pass(arr, size, swappedAtLeastOnce);
	if (swappedAtLeastOnce)
		bubbleSort(arr, size);
}