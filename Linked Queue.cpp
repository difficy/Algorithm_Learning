#include<iostream>
//链式队列，尾插头出
struct ListNode {
	ListNode* previous;
	int val;
	ListNode* next;
	ListNode(int value = 0)
		:val(value)
		,next(nullptr)
		,previous(nullptr)
	{ }
};

class Person {
public:
	Person() {
		head = new ListNode;
		head->next = head;
		head->previous = head;
	}

	~Person() {
		if (head == nullptr) {
			return;
		}
		ListNode* p = head->next;
		ListNode* q = nullptr;
		while (p != head) {
			q = p;
			p = p->next;
			delete q;
		}
		delete head;
		head = nullptr;
	}

	void push(int val) {
		if (head == nullptr) {
			throw "List is null";
		}
		ListNode* node = new ListNode(val);
		ListNode* p = head->previous;
		p->next = node;
		node->previous = p;
		head->previous = node;
		node->next = head;
	}

	void pop() {
		if (head == nullptr || head->next == head) {
			throw "no node";
		}
		ListNode* p = head->next;
		head->next = p->next;
		p->next->previous = head;
		delete p;
		p = nullptr;
	}

	bool empty() {
		return head == head->next;
	}

	int top() {
		if (head == nullptr || head->next == head) {
			throw "no node";
		}
		return head->next->val;
	}

	int count() {
		if (head == nullptr || head->next == head) {
			throw "no node";
		}
		ListNode* p = head->next;
		int num = 0;
		while (p != head) {
			p = p->next;
			num++;
		}
		return num;
	}

private:
	ListNode* head;//头指针
};

void Test01() {
	Person p;
	/*for (int i = 1; i <= 10; i++) {
		p.push(i);
	}
	while (!p.empty()) {
		std::cout << p.top() << "  ";
		p.pop();
	}*/
	p.push(21);
	p.push(123);
	std::cout << p.top() << " ";
	p.pop();
	std::cout << p.top() << " ";
}
int main() {
	Test01();
	return 0;
 }