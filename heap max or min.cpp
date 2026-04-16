#if 0
#include "head.h"

void show(int a[]) {
	for (int i = 0; i < 3; i++) {
		std::cout << a[i] << "  ";
	}
	std::cout << std::endl;
}

void downheap(int a[]) {
	if (comp(a[1], a[2])) {
		if (comp(a[1], a[0]))swap(a[0], a[1]);
	}
	else {
		if (comp(a[2], a[0]))swap(a[0], a[2]);
	}
}

void upheap(int a[]) {
	if (mincomp(a[1], a[2])) {
		if (mincomp(a[1], a[0]))swap(a[0], a[1]);
	}
	else {
		if (mincomp(a[2], a[0]))swap(a[0], a[2]);
	}
}

void maxthree(int a[], int size) {
	int maxtop[3] = { a[0], a[1], a[2] };
	upheap(maxtop);
	for (int i = 3; i < size; i++) {
		if (a[i] > maxtop[0]) {
			maxtop[0] = a[i];
			upheap(maxtop);
		}
	}
	show(maxtop);
}

void minthree(int a[], int size) {
	int mintop[3] = { a[0], a[1], a[2] };
	downheap(mintop);
	for (int i = 3; i < size; i++) {
		if (a[i] < mintop[0]) {
			mintop[0] = a[i];
			downheap(mintop);
		}
	}
	show(mintop);
}

void test() {
	srand((unsigned int)time(NULL));
	int arr[10];
	for (auto& a : arr) {
		a = rand() % 100 + 1;
	}
	for (auto& a : arr) {
		std::cout << a << "  ";
	}
	std::cout << std::endl;
	//最大
	maxthree(arr, 10);
	//最小
	minthree(arr, 10);
}
int main() {
	test();
	return 0;
}
#endif // 0