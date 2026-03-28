#include<iostream>
#include<ctime>
#include<cstdlib>

struct DoublyListNode {
	DoublyListNode* previous;
	int val;
	DoublyListNode* Next;
	DoublyListNode(int val = 0)
		:previous(nullptr)
		,val(val)
		,Next(nullptr)
	{}
};

class DoublyPerson {
public:
	DoublyPerson() {
		head = new DoublyListNode();
	}
	~DoublyPerson() {
		DoublyListNode* p = head;
		while (p != nullptr) {
			p = p->Next;
			delete head;
			head = p;
		}
		head = nullptr;
	}
	void push_back(int val) {//尾插
		if (head == nullptr) {
			return;
		}
		DoublyListNode* node = new DoublyListNode(val);
		DoublyListNode* p = head;
		while (p->Next != nullptr) {
			p = p->Next;
		}
		p->Next = node;
		node->previous = p;
	}

	void push_front(int val) {//头插
		if (head == nullptr) {
			return;
		}
		DoublyListNode* node = new DoublyListNode(val);
		node->Next = head->Next;
		if (head->Next != nullptr) {
			head->Next->previous = node;
		}
		
		head->Next = node;
		node->previous = head;
	}

	void pop_insert(int num) {
		if (head == nullptr || head->Next == nullptr) {
			return;
		}
		DoublyListNode* p = head->Next;
		while (p != nullptr) {
			if (p->val == num) {
				DoublyListNode* q = p->previous;
				if (p->Next != nullptr) {
					q->Next = p->Next;
					p->Next->previous = q;
				}
				else {
					q->Next = p->Next;
				}
				delete p;
				return;
			}
			p = p->Next;
		}
		if (p == nullptr) {
			std::cout << "无" << std::endl;
		}
	}

	void show() {//遍历输出
		if (head == nullptr || head->Next == nullptr) {
			return;
		}
		DoublyListNode* p = head->Next;
		while (p != nullptr) {
			std::cout << p->val << "  ";
			p = p->Next;
		}
		std::cout << std::endl;
	}

	void retshow() {
		if (head == nullptr || head->Next == nullptr) {
			return;
		}
		DoublyListNode* L = head;
		while (L->Next != nullptr) {
			L = L->Next;
		}
		while (L->previous != nullptr) {
			std::cout << L->val << "  ";
			L = L->previous;
		}
		std::cout << std::endl;
	}

private:
	DoublyListNode* head;
};

void DoublyTest01() {
	DoublyPerson dp;
	dp.push_back(21);
	dp.push_back(23);
	dp.push_back(24);
	dp.push_front(232);
	dp.push_front(21213);
	dp.show();
	dp.retshow();
	dp.pop_insert(4);
	dp.show();
}

int main() {
	DoublyTest01();
	return 0;
}