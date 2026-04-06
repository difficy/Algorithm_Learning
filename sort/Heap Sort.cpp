#include<iostream>
#include<functional>
#include<algorithm>
#include<ctime>

using Comp = std::function<bool(int, int)>;
Comp comp = std::greater<int>();

void Que_down(int arr[], int head, int size) {
	int val = arr[head];
	while (head < size / 2) {
		int child = head * 2 + 1;
		if (child + 1 < size && comp(arr[child + 1], arr[child])) {
			child++;
		}
		if (comp(arr[child], val)) {
			arr[head] = arr[child];
			head = child;
		}
		else {
			break;
		}
	}
	arr[head] = val;
}

void HeapSort(int size, int arr[]) {
	int n = size - 1;
	for (int i = (n - 1) / 2; i >= 0; i--) {
		Que_down(arr, i, size);
	}

	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;

	for (int i = n; i > 0; i--) {
		std::swap(arr[0], arr[i]);
		size--;
		Que_down(arr, 0, size);
		
	}
}
void Test() {
	srand((unsigned int)time(NULL));
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = (rand() % 100 + 1);
	}
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;
	HeapSort(10, arr);
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << "  ";
	}
	std::cout << std::endl;
}
#if 0
int main() {
	Test();
	return 0;
}
#endif // 0

