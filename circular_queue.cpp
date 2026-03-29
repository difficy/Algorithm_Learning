#include<iostream>

class Person {
public:
	Person(int size = 10)
		: head(0)
		, tail(0)
		, Que_size(size) {
		Queue = new int[Que_size];
	}

	~Person() {
		delete[] Queue;
		Queue = nullptr;
	}

	void push(int val) {//入队
		if ((tail + 1) % Que_size == head) {
			expend(2 * Que_size);
		}
		Queue[tail] = val;
		tail = (tail + 1) % Que_size;
	}

	void pop() {//出队
		if (tail == head) {
			throw "queue is empty";
		}
		head = (head + 1) % Que_size;
	}

	int Que_head() const {//返回队首元素
		return Queue[head];
	}

	int Que_tail() const {//返回队头元素
		return Queue[(tail - 1 + Que_size) % Que_size];
	}

	int Que_count() const {//返回元素数量
		int count = 0;
		int num = head;
		while (num != tail) {
			num = (num + 1) % Que_size;
			count++;
		}
		return count;
	}

	bool Que_empty() const {//判断队列是否为空
		return tail == head;
	}

private:
	int* Queue;
	int head;//队头
	int tail;//队尾
	int Que_size;//队列容量

	void expend(int size) {//扩容
		int* p = new int[size];
		int q = head;
		int num = 0;
		while (q != tail) {
			p[num] = Queue[q];
			q = (q + 1) % Que_size;
			num++;
		}
		head = 0;
		tail = num;
		delete[] Queue;
		Queue = p;
		Que_size = size;
		p = nullptr;
	}
};

void Test01() {
	Person p;
	for (int i = 1; i <= 20; i++) {
		p.push(i);
	}
	std::cout << p.Que_count() << std::endl;
	while (!p.Que_empty()) {
		std::cout << p.Que_head() << "  ";
		p.pop();
	}
	std::cout << std::endl;
	p.push(2313);
	std::cout << p.Que_head() << std::endl;
}
int main() {
	Test01();
	return 0;
}