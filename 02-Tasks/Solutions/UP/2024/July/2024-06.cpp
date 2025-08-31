void insert(int* arr, int index) {
	int key = arr[index];
	int j = index - 1
	while (j >= 0 && arr[j] > key) {
		arr[j + 1] = arr[j];
		j = j - 1;
	}
	arr[j + 1] = key;
}

void insertSort(int* arr, int size){
	for(int i = 1; i < size; i++) {
		insert(arr, i); // 7 4 1 2
	}
}