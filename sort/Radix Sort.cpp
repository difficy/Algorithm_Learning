#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include"Sort.h"

void RadixSort(int arr[], int size) {
	int x = 1;
	int y = 10;
	std::vector<std::vector<int>> vecs;
	int maxdata = abs(arr[0]);
	for (int i = 0; i < size; i++) {
		if (maxdata < abs(arr[i])) {
			maxdata = abs(arr[i]);
		}
	}
	int len = std::to_string(maxdata).size();//获取元素的最大位数
	for (int n = 0; n < len; n++, x *= 10, y *= 10) {
		vecs.resize(20);
		for (int i = 0; i < size; i++) {
			vecs[arr[i] % y / x + 10].push_back(arr[i]);
		}
		int i = 0;
		for (auto& vec : vecs) {
			for (auto& v : vec) {
				arr[i++] = v;
			}
		}
		vecs.clear();
	}
}

void Test6() {
	srand((int)time(NULL));
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = (rand() % 100 - 50);
	}
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;
	RadixSort(arr, sizeof(arr) / sizeof(int));
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;
}

int main() {
	Test6();
	return 0;
}