#include<iostream>
#include<ctime>
#include"Sort.h"

//πÈ≤¢≈≈–Ú
void MergeSort(int a[], int front, int last, int* arr) {
	if (front == last) {
		return;
	}
	int mid = (front + last) / 2;
	int left = front;
	int right = mid + 1;
	MergeSort(a, left, mid, arr);
	MergeSort(a, right, last, arr);
	int i = 0;
	while (left <= mid && right <= last) {
		if (a[left] <= a[right]) {
			arr[i] = a[left];
			i++;
			left++;
		}
		else {
			arr[i] = a[right];
			i++;
			right++;
		}
	}
	while (left <= mid) {
		arr[i++] = a[left++];
	}
	while (right <= last) {
		arr[i++] = a[right++];
	}
	int num = 0;
	while (num < i) {
		a[front] = arr[num];
		front++;
		num++;
	}
	return;
}


void test6() {
	int* arr = new int[20];
	srand((unsigned int)time(NULL));
	int a[20];
	for (int i = 0; i < 20; i++) {
		a[i] = rand() % 100 + 1;
	}
	for (int& arr : a) {
		std::cout << arr << "  ";
	}
	std::cout << "\n";
	MergeSort(a, 0, sizeof(a) / sizeof(int) - 1, arr);
	for (int& arr : a) {
		std::cout << arr << "  ";
	}
	std::cout << "\n";
	delete[] arr;
	arr = nullptr;
}

#if 0
int main() {
	test6();
	return 0;
}
#endif // 0