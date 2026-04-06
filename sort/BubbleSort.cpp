#include<iostream>
#include<ctime>
#include"Sort.h"

//冒泡排序
void Bubble(int arr[], int size) {
	bool flag = false;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j + 1] < arr[j]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				flag = true;
			}
		}
		if (!flag) {
			//没有进行任何数据交换，表明数据已经排序完成，减少循环次数
			return;
		}
	}
}

void test() {
	srand((unsigned int)time(NULL));
	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 20 + 1;
	}
	for (int& arr : a) {
		std::cout << arr << "  ";
	}
	std::cout << std::endl;
	Bubble(a, sizeof(a) / sizeof(int));
	for (int& arr : a) {
		std::cout << arr << "  ";
	}
	std::cout << std::endl;
}
#if 0
int main() {
	test();
	return 0;
}
#endif // 0

