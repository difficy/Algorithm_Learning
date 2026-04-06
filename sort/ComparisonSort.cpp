#include<iostream>
#include<ctime>
#include"Sort.h"

//—°‘Ò≈≈–Ú
void comparison(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int min = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		if (min != i) {
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

void test1() {
	srand((unsigned int)time(NULL));
	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 20 + 1;
	}
	for (int& arr : a) {
		std::cout << arr << "  ";
	}
	std::cout << std::endl;
	comparison(a, sizeof(a) / sizeof(int));
	for (int& arr : a) {
		std::cout << arr << "  ";
	}
	std::cout << std::endl;
}
#if 0
int main() {
	test1();
	return 0;
}
#endif // 0

