#include<iostream>
#include<ctime>
#include"Sort.h"
//快速排序
/*
1.快速排序在进行的过程中，会逐渐趋于有序，可以在中间使用插入排序来优化快速排序
因为在趋于有序的数组中，插入排序是最快的
2.或者在选择基准数时尽量选取中间数，因为数组有序/接近有序时，快排退化为O(n?)时间复杂度

详见：Quick Sort Optimization.cpp
*/
int realSort(int a[], int front, int last) {
	int val = a[front];
	while (front < last) {
		while (front < last && a[last] >= val) {
			last--;
		}
		if (front < last) {
			a[front] = a[last];
		}
		
		while (front < last && a[front] <= val) {
			front++;
		}
		if (front < last) {
			a[last] = a[front];
		}
		
	}
	a[front] = val;
	return front;
}

void QuickSort(int a[], int front, int last) {
	//判断递归终止
	if (front >= last) {
		return;
	}

	//返回基准数字的下标
	int pos = realSort(a, front, last);
	
	//递归调用
	QuickSort(a, front, pos - 1);	//左
	QuickSort(a, pos + 1, last);	//右
}

void test4() {
	srand((unsigned int)time(NULL));
	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 20 + 1;
	}
	for (int& arr : a) {
		std::cout << arr << "  ";
	}
	std::cout << "\n";
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	for (int& arr : a) {
		std::cout << arr << "  ";
	}
	std::cout << "\n";
}

#if 0
int main() {
	test4();
	return 0;
}
#endif // 0

