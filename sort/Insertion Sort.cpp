#include<iostream>
#include<ctime>
#include"Sort.h"

//≤Â»Î≈≈–Ú
void insertion(int a[], int size) {
	for (int i = 1; i <= size - 1; i++) {
		int val = a[i];
		int j = i - 1;
		for (; j >= 0; j--) {
			if (val >= a[j]) {
				break;
			}
			else {
				a[j + 1] = a[j];
			}
		}
		a[j + 1] = val;
	}
}

void test2() {
	srand((unsigned int)time(NULL));
	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 20 + 1;
	}
	for (int& arr : a) {
		std::cout << arr << "  ";
	}
	std::cout << "\n";
	insertion(a, sizeof(a) / sizeof(int));
	for (int& arr : a) {
		std::cout << arr << "  ";
	}
	std::cout << "\n";
}
#if 0
int main() {
	test2();
	return 0;
}
#endif // 0

