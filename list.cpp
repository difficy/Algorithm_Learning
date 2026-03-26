#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

struct Listnode
{
	int val;
	Listnode* next;
	Listnode(int val = 0) :val(val), next(nullptr) {};//默认初始化
};
//含哑节点链表
class Person {//单链表
	friend Listnode* merge(Person& p1, Person& p2);
	friend void Test04();
public:
	Person() {
		head = new Listnode();
	}

	~Person() {//释放堆区内存
		if (head == nullptr) {
			
			delete head;
			return;
		}
		if (head->next == nullptr) {
			delete head->next;
			return;
		}
		Listnode* fast = head;
		Listnode* slow = head;
		while (fast != nullptr && fast->next != nullptr) {//判断链表是否有环
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {
				fast = head;
				while (fast != slow) {
					fast = fast->next;
					slow = slow->next;
				}
				slow = slow->next;
				fast->next = nullptr;
				Listnode* T = slow;
				while (T->next != nullptr) {
					T = slow->next;
					delete slow;
					slow = T;
				}
				Listnode* p = head;
				while (p != nullptr) {
					Listnode* q = p->next;
					delete p;
					p = q;
				}
				head = nullptr;
			}
			return;
		}

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

public://判断链表是否存在环
	void tt1() {//连成环
		Listnode* fast = head;
		while (fast->next != nullptr) {
			fast = fast->next;
		}
		int count = 0;
		Listnode* slow = head;
		while (slow != nullptr && count < 3) {
			slow = slow->next;
			count++;
		}
		if (slow == nullptr) {
			return;
		}
		fast->next = slow;
	}

	bool circleList(int &circle) {//判断是否存在环
		if (head == nullptr || head->next == nullptr) {
			return false;
		}
		Listnode* fast = head;
		Listnode* slow = head;
		while (fast != nullptr && fast->next != nullptr) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) {
				fast = head;
				while (fast != slow) {
					fast = fast->next;
					slow = slow->next;
				}
				circle = fast->val;
				return true;
			}
		}
		return false;
	}
	
private:
	Listnode* head;
	Listnode* reverse(Listnode* head) {//递归逆置,函数实现
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		Listnode* newhead = reverse(head->next);
		head->next->next = head;
		head->next = nullptr;
		return newhead;
	}
};
//不含哑节点链表
class Person2 {//单向循环链表
public:

	~Person2() {
		if (head == tail) {
			delete head;
		}
		else {
			Listnode* p = head;
			while (head != tail) {
				head = head->next;
				delete p;
				p = head;
			}
			delete p;
			p = nullptr;
		}
		head = nullptr;
		tail = nullptr;
	}

	void push_back(int val) {//尾插
		Listnode* node = new Listnode(val);
		if (head == nullptr) {//处理链表中没有任何节点的问题
			head = node;
			tail = node;
			tail->next = head;
			return;
		}
		tail->next = node;
		tail = tail->next;
		tail->next = head;
	}

	void push_front(int val) {//头插
		Listnode* node = new Listnode(val);
		if (head == nullptr) {//处理链表中没有任何节点的问题
			head = node;
			tail = head;
			tail->next = head;
			return;
		}
			node->next = head;
			head = node;
			tail->next = head;
	}
	
	void pop_back() {//尾删
		if (head == tail) {
			delete tail;
			head = nullptr;
			tail = nullptr;
			return;
		}
		Listnode* p = head;
		while (p->next != tail) {
			p = p->next;
		}
		delete tail;
		tail = p;
		tail->next = head;
	}

	void pop_front() {//头删
		if (head == tail) {
			delete head;
			head = nullptr;
			tail = nullptr;
			return;
		}
		Listnode* p = head;
		head = head->next;
		delete p;
		p = nullptr;
		tail->next = head;
	}

	void pop_insert(int val) {//删除中间某一节点
		if (head == tail || (head == tail && head->val != val)) {
			delete head;
			head = nullptr;
			tail = nullptr;
			std::cout << "该节点不存在" << std::endl;
			return;
		}
		Listnode* p = head;
		Listnode* q = nullptr;
		while (p->val != val) {
			p = p->next;
			if (p == head) {
				break;
			}
			if (p->next->val == val) {
				q = p;
			}
		}
		if (head == tail) {
			delete head;
			head = nullptr;
			tail = nullptr;
			p = nullptr;
		}
		else if (p == tail) {
			tail = q;
			tail->next = head;
			delete p;
			p = nullptr;
		}
		else if (p == head) {
			head = head->next;
			delete p;
			p = nullptr;
			tail->next = head;
		}
	}

	void show() {//遍历输出
		if (head == nullptr) {
			return;
		}
		Listnode* p = head;
		std::cout << p->val << "  ";
		p = p->next;
		while (p != head) {
			std::cout << p->val << "  ";
			p = p->next;
		}
		std::cout << std::endl;
	}

	void Josephus(int k, int m) {//约瑟夫环问题
		/*
		有 n 个人围成一圈，从某个人开始按顺序从 1 报数，数到 m 的人就出列；
		接着从出列的下一个人重新从 1 开始报数，再数到 m 的人出列；
		直到全部人出列，输出出列顺序
		*/
		Listnode* newhead = nullptr;
		Listnode* p = head;
		Listnode* q = newhead;//指向新链表的指针
		for (int i = 1; i <= k - 2; i++) {//找出起始位置的前一个位置，作为慢指针的起点，方便后续循环
			p = p->next;
		}
		std::cout << p->val << std::endl;
		Listnode* slow = p;
		Listnode* fast = p->next;
		int count = 1;
		int num = 0;
		while (slow != slow->next) {
			while (count < m) {//找到要被移出的节点
				count++;
				slow = slow->next;
				fast = fast->next;
			}
			count = 1;
			if (slow == nullptr || fast == nullptr) {
				return;
			}
			slow->next = fast->next;
			if (num == 0) {//将该节点放在新的链表中
				newhead = fast;
				newhead->next = nullptr;
				num++;
				q = newhead;
			}
			else {
				fast->next = nullptr;
				q->next = fast;
				q = q->next;
			}
			fast = slow->next;
		}
		if (slow == nullptr || q == nullptr) {
			return;
		}
		slow->next = nullptr;
		q->next = slow;
		Listnode* run = newhead;
		while (run != nullptr) {
			std::cout << run->val << " ";
			run = run->next;
		}
		std::cout << std::endl;
	}
private:
	Listnode* head = nullptr;//头指针
	Listnode* tail = nullptr;//尾指针
};

Listnode* merge(Person& p1, Person& p2) {//链接两个有序链表
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

void get_inter(Listnode* l1, Listnode* l2) {//获取相交链表
	Listnode* p = l1;
	Listnode* q = l2;
	while (q->next != nullptr) {
		q = q->next;
	}
	int count = 0;//计数器
	while (p != nullptr && count < 3) {
		p = p->next;
		count++;
	}
	q->next = p;
}

Listnode* intersect(Listnode* l1,Listnode* l2) {//判断是否相交并返回交点
	int l1_number = 1;
	int l2_number = 1;
	Listnode* p = l1;
	Listnode* q = l2;
	while (p != nullptr) {
		p = p->next;
		l1_number++;
	}
	while (q != nullptr) {
		q = q->next;
		l2_number++;
	}
	p = l1;
	q = l2;
	int count = 0;
	if (l1_number > l2_number) {
		int difference = l1_number - l2_number;
		while (p != q) {
			p = p->next;
			count++;
			if (count > difference) {
				q = q->next;
			}
		}
	}
	else {
		int difference = l2_number - l1_number;
		while (p != q) {
			q = q->next;
			count++;
			if (count > difference) {
				p = p->next;
			}
		}
	}
	Listnode* id = p;
	return id;
}

void pop_delete(Listnode* l1, Listnode* l2, Listnode* valua) {//释放交叉链表内存
	Listnode* p = l1;
	while (p->next != valua) {
		p = p->next;
	}
	p->next = nullptr;
	p = l1->next;
	while (p != nullptr) {
		delete l1;
		l1 = p;
		p = p->next;
	}
	l1 = nullptr;
	p = l2->next;
	while (p != nullptr) {
		delete l2;
		l2 = p;
		p = p->next;
	}
	l2 = nullptr;
}

void show(Listnode* L) {
	while (L != nullptr) {
		cout << L->val << "  ";
		L = L->next;
	}
	cout << endl;
}

void Test01() {//测试1
	srand((unsigned int)time(0));//随机数种子
	Person p;
	for (int i = 6; i <= 10; i++) {
		p.push_back(rand() % 20 + 21);//随机数21~40
	}
	p.show();
	p.reverselist2();
	p.show();
}

void Test02() {//合并有序链表测试
	Person p1;
	p1.push_back(11);
	p1.push_back(14);
	p1.push_back(24);
	p1.push_back(33);
	p1.push_back(45);
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

void Test03() {//"环"测试
	Person p;
	int value = 0;
	for (int i = 1; i <= 10; i++) {
		p.push_back(i);
	}
	if (!p.circleList(value)) {
		std::cout << "不存在环" << std::endl;
	}
	p.tt1();
	if (p.circleList(value)) {
		std::cout << "存在环" << std::endl;
	}
	std::cout << value << std::endl;
}

void Test04() {//链表相交测试
	srand((unsigned int)time(NULL));
	Person p1;
	Person p2;
	Listnode* head1 = new Listnode();
	Listnode* head2 = new Listnode();
	for (int i = 1; i <= 5; i++) {
		p1.push_front(rand() % 40 + 21);
		Listnode* node = new Listnode(p1.head->next->val);
		node->next = head1->next;
		head1->next = node;
	}
	show(head1->next);
	for (int i = 1; i <= 5; i++) {
		p2.push_front(rand() % 40 + 21);
		Listnode* node = new Listnode(p2.head->next->val);
		node->next = head2->next;
		head2->next = node;
	}
	show(head2->next);
	Listnode* l1 = head1->next;
	Listnode* l2 = head2->next;
	std::cout << "交点" << std::endl;
	get_inter(l1,l2);
	show(l1);
	show(l2);
	std::cout << "/////////" << std::endl;
	Listnode* L = intersect(l1, l2);
	std::cout << L->val << std::endl;
	pop_delete(l1, l2, L);
}

void Test05() {//Person2测试
	Person2 p;
	p.push_back(211);
	p.push_front(21);
	p.pop_insert(21);
	p.show();
}

void Test06() {//测试06：约瑟夫环
	Person2 p;
	for (int i = 1; i <= 10; i++) {
		p.push_back(i);
	}
	p.show();
	p.Josephus(5, 7);
}

int main() {
	Test01();
	Test02();
	Test03();
	Test04();
	Test05();
	Test06();
	return 0;
}