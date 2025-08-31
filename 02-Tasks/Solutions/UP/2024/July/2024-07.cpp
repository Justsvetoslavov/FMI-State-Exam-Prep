#include <iostream >

void rotateArray(int* nums,int k, int size) {
	int arr[] = { 1, -2, 13, 40, 5 };
	nums = arr;
	if (size == 0 || k % size == 0)
		return;
	k %= size;
	std::reverse(nums, nums + size); 
	std::reverse(nums, nums + k);
	std::reverse(nums + k, nums + size);
}