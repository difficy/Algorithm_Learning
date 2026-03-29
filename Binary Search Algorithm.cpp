#include<iostream>

int Binary(int arr[], int f, int l, int val) {
	if (arr[f] == val) {
		return f;
	}
	if (arr[f] != val && f == l) {
		return -1;
	}
	int n = (f + l) / 2;
	if (arr[n] > val) {
		return Binary(arr, f, n - 1, val);
	}
	else if(arr[n] < val) {
		return Binary(arr, n + 1, l, val);
	}
}

int main() {
	int arr[] = { 1,23,34,54,65,677,879 };
	int i = Binary(arr, 0, sizeof(arr) / sizeof(int) - 1, 0);
	std::cout << i << std::endl;
	return 0;
}