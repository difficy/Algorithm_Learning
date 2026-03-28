#include<iostream>

class Liststack {
public:
	Liststack() {
		head = new ListNode();
	}

	~Liststack() {
		ListNode* p = head;
		while (p != nullptr) {
			head = head->next;
			delete p;
			p = head;
		}
	}

	void push(int val) {
		ListNode* node = new ListNode(val);
		node->next = head->next;
		head->next = node;
	}

	void pop() {
		if (head == nullptr || head->next == nullptr) {
			throw "stack is empty";
		}
		ListNode* p = head->next;
		head->next = p->next;
		delete p;
		p = nullptr;
	}

	int top() {
		if (head == nullptr || head->next == nullptr) {
			throw "stack is empty";
		}
		return head->next->val;
	}

	bool empty() {
		return head->next == nullptr;
	}


private:
	struct ListNode {
		int val;
		ListNode* next;
		ListNode(int val = 0)
			:val(val)
			, next(nullptr){ }
	};
	ListNode* head;
};

void test02() {
	Liststack ls;
	int a[] = { 1,21,3234,5,45,6,53,4 };
	for (int a : a) {
		ls.push(a);
	}
	while (!ls.empty()) {
		std::cout << ls.top() << "  ";
		ls.pop();
	}
	ls.push(21);
	std::cout << ls.top() << std::endl;
}

int main() {
	test02();
	return 0;
}