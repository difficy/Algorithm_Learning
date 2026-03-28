#include<iostream>

class Stack {
public:
	Stack(int size = 10)
		:mtop(0)
		, mstactsize(size)
	{
		mstact = new int[size];
	}
	~Stack() {
		delete[] mstact;
		mstact = nullptr;
	}

	void push(int val) {//ÈëÕ»
		if (mtop == mstactsize) {
			empend(2 * mstactsize);
		}
		mstact[mtop] = val;
		mtop++;
	}

	void pop() {//³öÕ»
		if (mtop == 0)
			throw "stact is empty!";
		mtop--;
	}

	int top() const {//Êä³öÕ»¶¥ÔªËØ
		if (mtop == 0)
			throw "stact is empty!";
		return mstact[mtop - 1];
	}

	bool empty() const {//ÅÐ¶ÏÕ»Öª·ñÎª¿Õ
		return mtop == 0;
	}

private:
	void empend(int size) {//À©ÈÝ
		int* p = new int[size];
		memcpy(p, mstact, mstactsize * sizeof(int));
		delete[] mstact;
		mstact = p;
		mstactsize = size;

	}

private:
	int* mstact;//Õ»
	int mtop;//Õ»¶¥
	int mstactsize;//Õ»µÄÈÝÁ¿
};

void test01() {
	Stack ms;
	int a[] = { 1,21,3234,5,45,6,53,4 };
	for (int a : a) {
		ms.push(a);
	}
	while (!ms.empty()) {
		std::cout << ms.top() << "  ";
		ms.pop();
	}
	ms.push(21);
	std::cout << ms.top() << std::endl;
}

int main() {
	test01();
	return 0;
}