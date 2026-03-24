#include<iostream>
#include<ctime>
using namespace std;
//含哑节点链表
struct Listnode
{
	int val;
	Listnode* next;
	Listnode(int val = 0) :val(val), next(nullptr) {};//默认初始化
};

class Person {
	friend void reversemerge(Person& p1, Person& p2);
	friend Listnode* merge(Person& p1, Person& p2);
public:
	Person() {
		head = new Listnode();
	}

	~Person() {//释放堆区内存
		Listnode* p = head;
		while (p != nullptr) {
			Listnode* q = p->next;
			delete p;
			p = q;
		}
		head = nullptr;
	}

	void push_back(int val) {//尾插
		Listnode* node = new Listnode(val);
		Listnode* p = head;
		while (p->next != nullptr) {
			p = p->next;
		}
		p->next = node;
	}

	void push_front(int val) {//头插
		Listnode* node = new Listnode(val);
		Listnode* p = head->next;
		node->next = p;
		head->next = node;
	}

	void show() {//遍历输出
		Listnode* p = head->next;
		while (p != nullptr) {
			cout << p->val << "  ";
			p = p->next;
		}
		cout << endl;
	}

	void pop_back() {//尾删
		Listnode* p = head;

		if (head->next == nullptr) {
			return;
		}
		while (p->next->next != nullptr) {
			p = p->next;
		}
		Listnode* q = p->next;
		p->next = nullptr;
		delete q;
	}

	void pop_front() {//头删
		if (head->next == nullptr) {
			return;
		}
		Listnode* p = head->next;
		head->next = p->next;
		delete p;
	}

	void pop_insert(int num) {//删除值为num的所有节点
		Listnode* p = head;
		Listnode* q = p->next;
		while (p->next != nullptr && q->next != nullptr) {
			if (q->val == num) {
				p->next = q->next;
				delete q;
				q = p->next;
				break;
			}
			p = q;
			q = q->next;
		}
	}

	void reverselist1() {//逆置:用前插法思路
		Listnode* p = head->next;
		if (p == nullptr) {
			return;
		}
		head->next = nullptr;
		while (p != nullptr) {
			Listnode* q = p->next;
			p->next = head->next;
			head->next = p;
			p = q;
		}
	}

	void reverselist2() {//递归逆置：函数调用
		head->next = reverse(head->next);
		/*
		如何递归？
		将该链表这个大问题拆分成两个子问题，从最小子问题开始推
		当最小子问题的head指向的节点为最后一个节点时，需要直接返回该head节点
		重新在第一层归中定义新节点作为逆置后的新头节点，指向返回的节点
		这样逆置后的第一个节点就链接成功了，同时大问题被拆分成两个子问题
		另外一个子问题在每一层递归中是作为头节点的，然而逆置的头节点是从后往前的
		所以将每一层递归的头节点单独作为一个子问题，在接收到“归”后，将新定义的节点的next指向头节点
		将头节点的next置空，返回该新节点，递归程序的编写就完成了
		*/
	}

	Listnode* get_list() {//获取链表头节点
		return head->next;
	}

private:
	Listnode* head;
	Listnode* reverse(Listnode* head) {//递归逆置,函数实现
		if (head->next == nullptr || head == nullptr) {
			return head;
		}
		Listnode* newhead = reverse(head->next);
		head->next->next = head;
		head->next = nullptr;
		return newhead;
	}
};

Listnode* merge(Person& p1, Person& p2) {
	//链接两个有序链表，由于当前函数调用完成后，析构函数会自动清空全部内存
	//此时，如果返回链表的子节点仍然是原p1 p2的节点，就会崩溃，因为析构已经将这一部分内存释放了
	//所以就需要重新定义链表节点来存放数据，在函数调用完成后释放
	Listnode* l1 = p1.get_list();
	Listnode* l2 = p2.get_list();
	Listnode* l3 = new Listnode();
	Listnode* p = l1;
	Listnode* q = l2;
	Listnode* T = l3;
	while (p != nullptr && q != nullptr) {
		if (p->val <= q->val) {
			T->next = new Listnode(p->val);
			p = p->next;
		}
		else {
			T->next = new Listnode(q->val);
			q = q->next;
		}
		T = T->next;
	}
	while (q != nullptr) {
		T->next = new Listnode(q->val);
		q = q->next;
		T = T->next;
	}
	while (p != nullptr) {
		T->next = new Listnode(p->val);
		p = p->next;
		T = T->next;
	}
	T = l3->next;
	delete l3;
	return T;
}

void reversemerge(Person& p1, Person& p2) {

}

void show(Listnode* L) {
	while (L != nullptr) {
		cout << L->val << "  ";
		L = L->next;
	}
	cout << endl;
}


void Test01() {
	srand((unsigned int)time(0));//随机数种子
	Person p;
	for (int i = 6; i <= 10; i++) {
		p.push_back(rand() % 20 + 21);//随机数21~40
	}
	p.show();
	p.reverselist2();
	p.show();
}

void Test02() {
	Person p1;
	p1.push_back(11);
	p1.push_back(14);
	/*p1.push_back(24);
	p1.push_back(33);
	p1.push_back(45);*/
	p1.show();
	Person p2;
	p2.push_back(10);
	p2.push_back(12);
	p2.push_back(23);
	p2.push_back(32);
	p2.push_back(45);
	p2.show();
	Listnode* L = merge(p1,p2);
	show(L);
	while (L != nullptr) {
		Listnode* tup = L->next;
		delete L;
		L = tup;
	}
	L = nullptr;
}

int main() {
	Test02();
	return 0;
}