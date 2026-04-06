#include<iostream>
#include<ctime>
#include"Sort.h"

//Ï£¶ûÅÅÐò
void ShellSort(int a[], int size) {
	for (int gap = size / 2; gap > 0; gap /=2) {
		for (int i = gap; i < size; i++) {
			int temp = a[i];
			int j = i - gap;
			for (; j >= 0; j -= gap) {
				if (temp >= a[j]) {
					break;
				}
				a[j + gap] = a[j];
			}
			a[j + gap] = temp;
		}
	}
}

void test3() {
	srand((unsigned int)time(NULL));
	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 20 + 1;
	}
	for (int& arr : a) {
		std::cout << arr << "  ";
	}
	std::cout << std::endl;
	ShellSort(a, sizeof(a) / sizeof(int));
	for (int& arr : a) {
		std::cout << arr << "  ";
	}
	std::cout << std::endl;
}
#if 0
int main() {
	test3();
	return 0;
}
#endif // 0

