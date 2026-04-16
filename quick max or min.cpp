#include"head.h"
//获取最大的5个数
const static int key = 5;

int quick(std::vector<int>&vecs, int left, int right) {
	if (left >= right) {
		return 0;
	}
	int index = vecs[left];
	int front = left;
	int last = right;
	while (left < right) {
		while (left < right && vecs[right] > index) {
			right--;
		}
		if (left < right) {
			vecs[left] = vecs[right];
			left++;
		}
		while (left < right && vecs[left] < index) {
			left++;
		}
		if (left < right) {
			vecs[right] = vecs[left];
			right--;
		}
	}
	vecs[left] = index;
	return left;
}

void Topk(std::vector<int>&vec, int left, int right) {
	if (left >= right) {
		return;
	}
	int idx = quick(vec, left, right);
	if (idx == vec.size() - key) {
		for (; idx < vec.size(); idx++) {
			std::cout << vec[idx] << "  ";
		}
		std::cout << std::endl;
		return;
	}
	else if (idx < vec.size() - key) {
		Topk(vec, idx + 1, right);
	}
	else {
		Topk(vec, left, idx - 1);
	}
}

void test2() {
	
	srand((unsigned int)time(NULL));
	//std::vector<int>vecs{ 13, 6, 20, 13, 50, 42, 23, 33, 1, 48, 34, 40, 47, 42, 36, 47, 6, 44, 46, 41 };
	std::vector<int>vecs;
	int a[20];
	for (int i = 0; i < 20; i++) {
		a[i] = rand() % 50 + 1;
		vecs.push_back(a[i]);
	}
	for (auto vec : vecs) {
		std::cout << vec << " ";
	}
	std::cout << std::endl;
	Topk(vecs, 0, vecs.size() - 1);
	std::cout << std::endl;
	for (auto vec : vecs) {
		std::cout << vec << " ";
	}
	std::cout << std::endl;
}

int main() {
	test2();
	return 0;
}