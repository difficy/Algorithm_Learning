#if 0
#include "head.h"
void show1(std::vector<pair<int, int>>vec) {
	for (auto vecs : vec) {
		std::cout << vecs.first << "一共出现：" << vecs.second << "次" << std::endl;
	}
}

//重复次数最多的5个

void upmin(std::vector<pair<int, int>>& heap, int size) {
	for (int i = (size - 2) / 2; i >= 0; i--) {
		int child = i * 2 + 1;
		if (child + 1 < size && mincomp(heap[child + 1].second, heap[child].second)) {
			child++;
		}
		if (!mincomp(heap[i].second, heap[child].second)) {
			swap(heap[i], heap[child]);
		}
	}
}

void remax(std::vector<int>& vecs, int size) {
	std::unordered_map<int, int>ma;
	for (auto vec : vecs) {
		ma[vec]++;
	}
	std::vector<pair<int, int>>heap;
	for (int i = 0; heap.size() < 5; i++) {
		bool n = true;
		for (auto& he : heap) {
			if (he.first == vecs[i]) {
				n = false;
				break;
			}
		}
		if (n) {
			heap.push_back(make_pair(vecs[i], ma[vecs[i]]));
		}

	}
	upmin(heap, heap.size());
	for (auto vec : ma) {
		bool n = true;
		for (auto& he : heap) {
			if (he.first == vec.first) {
				n = false;
				break;
			}
		}
		if (n && vec.second > heap[0].second) {
			heap[0].first = vec.first;
			heap[0].second = vec.second;
			upmin(heap, heap.size());
		}
	}
	show1(heap);
}

void test1() {
	srand((unsigned int)time(NULL));
	std::vector<int>vecs;
	for (int i = 0; i < 30; i++) {
		vecs.push_back(rand() % 50 + 1);
	}

	std::cout << std::endl;
	remax(vecs, vecs.size());
	sort(vecs.begin(), vecs.end());
	for (auto& a : vecs) {
		std::cout << a << "  ";
	}
}

int main() {
	test1();
	return 0;
}
#endif // 0

