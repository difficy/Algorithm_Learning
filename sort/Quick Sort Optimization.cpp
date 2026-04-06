#include<iostream>
#include<ctime>
#include"Sort.h"

//快排优化

//1.调用插入排序
int realSortnew1(int a[], int front, int last) {
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

void QuickSortnew1(int a[], int front, int last) {
	//判断递归终止
	if (front >= last) {
		return;
	}
	if (last - front < 10) {
		InsertionSort(a, front, last);
	}

	//返回基准数字的下标
	int pos = realSortnew1(a, front, last);

	//递归调用
	QuickSortnew1(a, front, pos - 1);	//左
	QuickSortnew1(a, pos + 1, last);	//右
}

void InsertionSort(int a[], int front, int last) {
	for (int i = front + 1; i <= last; i++) {
		int val = a[i];
		int j = i - 1;
		for (; j >= 0; j--) {
			if (val > a[j]) {
				break;
			}
			a[j + 1] = a[j];
		}
		a[j + 1] = val;
	}
}

//2.三数取中
int realSortnew2(int a[], int front, int last) {
	int val = a[(front + last) / 2];
	a[(front + last) / 2] = a[front];
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

void QuickSortnew2(int a[], int front, int last) {
	//判断递归终止
	if (front >= last) {
		return;
	}

	//返回基准数字的下标
	int pos = realSortnew2(a, front, last);

	//递归调用
	QuickSortnew1(a, front, pos - 1);	//左
	QuickSortnew1(a, pos + 1, last);	//右
}


void test5() {
	srand((unsigned int)time(NULL));
	int a[20];
	for (int i = 0; i < 20; i++) {
		a[i] = rand() % 100 + 1;
	}
	for (int& arr : a) {
		std::cout << arr << "  ";
	}
	std::cout << "\n";
	QuickSortnew1(a, 0, sizeof(a) / sizeof(int) - 1);
	for (int& arr : a) {
		std::cout << arr << "  ";
	}
	std::cout << "\n";
	QuickSortnew2(a, 0, sizeof(a) / sizeof(int) - 1);
	for (int& arr : a) {
		std::cout << arr << "  ";
	}
	std::cout << "\n";
}

#if 0
int main() {
	test5();
	return 0;
}
#endif // 0

