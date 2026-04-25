#include<iostream>
#include<ctime>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>

struct Node
{
	int val;
	Node* leftchild;
	Node* rightchild;
	Node(int value = 0)
		:val(value)
		,leftchild(nullptr)
		,rightchild(nullptr)
	{ }
};

class BSTree {
public:
	BSTree() {
		root = nullptr;
		Node_num = 0;
	}

	~BSTree() {
		del_Node(root);
	}

	void del_Node(Node* p) {//释放内存
		if (p == nullptr)return;
		del_Node(p->leftchild);
		del_Node(p->rightchild);
		delete p;
	}

	void show_inorder() {//中序输出
		back_order(root);
		std::cout << std::endl;
	}

	void show_layer() {//层序输出
		for(int i = 0; i < Level(); i++)
			layer_order(root, i);
		std::cout << std::endl;
	}

	int Level() {
		int level = get_level(root);
		return level;
	}

	int get_level(Node* nod) {
		if (nod == nullptr) {
			return 0;
		}
		int left = get_level(nod->leftchild);
		int right = get_level(nod->rightchild);
		return left > right ? left + 1 : right + 1;
	}

	void layer_order(Node* nod,int i) {//层序遍历
		if (nod == nullptr) {
			return;
		}
		if (i == 0) {
			std::cout << nod->val << "  ";
		}
		layer_order(nod->leftchild, i - 1);
		layer_order(nod->rightchild, i - 1);
	}

	void back_order(Node* nod) {//后序遍历
		if (nod == nullptr) {
			return;
		}
		back_order(nod->leftchild);
		back_order(nod->rightchild);
		std::cout << nod->val << "  ";
	}

	void In_order(Node* nod) {//中序遍历
		if (nod == nullptr) {
			return;
		}
		In_order(nod->leftchild);
		std::cout << nod->val << "  ";
		In_order(nod->rightchild);
	}

	void front_order(Node* nod) {//前序遍历
		if (nod == nullptr) {
			return;
		}
		std::cout << nod->val << "  ";
		front_order(nod->leftchild);
		front_order(nod->rightchild);
	}

	void push_Node(int val) {//插入
		Node_num++;
		if (root == nullptr) {
			root = new Node(val);
			return;
		}
		
		Node* p = root;
		if (p == nullptr)return;
		while (1) {
			if (p->val == val) {
				Node_num--;
				return;
			}
			if (p->val > val) {
				if (p->leftchild == nullptr) {
					Node* child = new Node(val);
					p->leftchild = child;
					break;
				}
				p = p->leftchild;
			}
			else {
				if (p->rightchild == nullptr) {
					Node* child = new Node(val);
					p->rightchild = child;
					break;
				}
				p = p->rightchild;
			}
		}
	}

	void pop_Node(int val) {
		if (root == nullptr) {
			return;
		}
		Node* pre = nullptr;
		Node* p = root;
		while (p != nullptr && p->val != val) {//寻找目标值
			pre = p;
			if (val < p->val) {
				p = p->leftchild;
			}
			else {
				p = p->rightchild;
			}
		}
		if (p == nullptr) {
			std::cout << "不存在这个值！" << std::endl;
			return;
		}
		std::cout << p->val << std::endl;
		//两边子树全为空
		if (p->leftchild == nullptr && p->rightchild == nullptr) {
			if (pre == nullptr) {
				root = nullptr;
				delete p;
			}
			else if (pre->leftchild == p) {
				delete pre->leftchild;
				pre->leftchild = nullptr;
			}
			else {
				delete pre->rightchild;
				pre->rightchild = nullptr;
			}
			p = nullptr;
		}
		//有一个子树不为空
		else if (p->leftchild == nullptr || p->rightchild == nullptr) {
			//如果待删除数为头节点
			Node* child = p->leftchild == nullptr ? p->rightchild : p->leftchild;
			if (pre == nullptr) {
				root = child;
			}
			else if (pre->leftchild == p)
				pre->leftchild = child;
			else
				pre->rightchild = child;
			delete p;
			p = nullptr;
		}
		//两个节点都不为空
		else {
			Node* q = p->leftchild;
			if (q->rightchild == nullptr) {
				p->val = q->val;
				p->leftchild = q->leftchild;
				delete q;
				Node_num--;
				return;
			}
			while (q->rightchild != nullptr) {
				if (q->rightchild->rightchild == nullptr)break;
				q = q->rightchild;
			}
			Node* m = q->rightchild;
			p->val = m->val;
			q->rightchild = m->leftchild;
			delete m;
			m = nullptr;
		}
		Node_num--;
	}

	int get_num() {
		return Node_num;
	}

private:
	Node* root;//根节点
	int Node_num;//节点个数
};

class rec_BSTree {
public:
	rec_BSTree()
		:Node_num(0)
		, root(nullptr)
	{
	}
	//回收
	~rec_BSTree() {
		del_Node(root);
	}
	void del_Node(Node* p) {//释放内存
		if (p == nullptr)return;
		del_Node(p->leftchild);
		del_Node(p->rightchild);
		delete p;
	}
	//插入
	void push_Node(int val) {
		if (root == nullptr) {
			Node* node = new Node(val);
			root = node;
			return;
		}
		Node* p = root;
		rec_push(p, val);
	}
	void rec_push(Node* p, int val) {
		if (p->val == val) {
			return;
		}
		else if (p->val > val) {
			if (p->leftchild == nullptr) {
				Node* node = new Node(val);
				p->leftchild = node;
				return;
			}
			rec_push(p->leftchild, val);
		}
		else if (p->val < val) {
			if (p->rightchild == nullptr) {
				Node* node = new Node(val);
				p->rightchild = node;
				return;
			}
			rec_push(p->rightchild, val);
		}
	}
	//查找
	Node* find_Node(int val) {
		Node* p = root;
		return rec_find(p, val);
	}
	Node* rec_find(Node* p, int val) {
		if (p == nullptr) {
			return nullptr;
		}
		if (val < p->val) {
			return rec_find(p->leftchild, val);
		}
		else if (val > p->val) {
			return rec_find(p->rightchild, val);
		}
		else {
			return p;
		}
	}
#if 0
//删除
	bool pop_node(int val) {
		Node* father = nullptr;
		Node* val_p = nullptr;
		Node* p = root;
		rec_pop(val, father, val_p, p);
		return true;
	}
	/// <summary>
	/// 递归删除BST树节点
	/// </summary>
	/// <param name="val">待删除值</param>
	/// <param name="val_p">指向待删除节点指针</param>
	/// <param name="p">查找</param>
	/// <returns></returns>
	void rec_pop(int val, Node* father, Node* val_p, Node* p) {
		if (p == nullptr)return;
		if (val_p == nullptr) {
			if (val == p->val) {
				val_p = p;
			}
			else  if (val < p->val) {
				father = p;
				rec_pop(val, father, val_p, p->leftchild);
			}
			else if (val > p->val) {
				father = p;
				rec_pop(val, father, val_p, p->rightchild);
			}
		}
		if (val_p != nullptr) {//已经找到待删除节点，开始寻找替换节点
			//如果是叶子节点
			if (val_p->leftchild == nullptr && val_p->rightchild == nullptr) {
				if (father == nullptr) {
					p = root;
					root = nullptr;
				}
				else {
					father->rightchild == val_p ? father->rightchild = nullptr 
						: father->leftchild = nullptr;
					p = val_p;
				}
			}
			//如果只有一个子树
			else if (val_p->leftchild == nullptr || val_p->rightchild == nullptr) {
				Node* child = val_p->leftchild == nullptr ? val_p->rightchild :
					val_p->leftchild;
				if (father == nullptr) {
					p = val_p;
					root = child;
				}
				else if (father->leftchild == val_p) {
					father->leftchild = child;
				}
				else father->rightchild = child;
				p = val_p;
			}
			//有左右子树
			else {
				Node* child = tool(val_p->leftchild);
				if (child->rightchild == nullptr) {
					val_p->val = child->val;
					val_p->leftchild = child->leftchild;
					p = child;
				}
				else {
					val_p->val = child->rightchild->val;
					p = child->rightchild;
					child->rightchild = child->rightchild->leftchild;
				}
			}
			delete p;
			p = nullptr;
			return;
		}
	}

	Node* tool(Node* q) {
		while (q->rightchild != nullptr) {
			if (q->rightchild->rightchild == nullptr)break;//找前驱
			q = q->rightchild;
		}
		return q;
	}
#endif // 0
	//删除
	void pop_val(int val) {
		Node* p = root;
		p = rec_pop(p, val);
	}

	Node* rec_pop(Node* node, int val) {
		if (node == nullptr) {
			return nullptr;
		}
		if (val == node->val) {
			if (node->leftchild == nullptr) {
				Node* temp = node->rightchild;
				delete node;
				return temp;
			}
			else if (node->rightchild == nullptr) {
				Node* temp = node->leftchild;
				delete node;
				return temp;
			}
			else if (node->leftchild != nullptr && node->rightchild != nullptr) {
				Node* temp = node->leftchild;
				while (temp->rightchild != nullptr)temp = temp->rightchild;
				node->val = temp->val;
				node->leftchild = rec_pop(node->leftchild, temp->val);
			}
		}
		else if (val > node->val) {
			node->rightchild = rec_pop(node->rightchild, val);
		}
		else {
			node->leftchild = rec_pop(node->leftchild, val);
		}
		return node;
	}
	//前序非递归
	void unvec_front_order() {
		if (root == nullptr)return;
		std::stack<Node*>sr;
		Node* p = root;
		sr.push(p);
		while (!sr.empty()) {
			p = sr.top();
			std::cout << p->val << "  ";
			sr.pop();
			if (p->rightchild != nullptr)sr.push(p->rightchild);
			if (p->leftchild != nullptr)sr.push(p->leftchild);
		}
	}
	//中序非递归
	void unvec_in_order() {
		if (root == nullptr)return;
		std::stack<Node*>sr;
		Node* p = root;
		while (p != nullptr || !sr.empty()) {
			while (p != nullptr) {
				sr.push(p);
				p = p->leftchild;
			}
			p = sr.top();
			std::cout << p->val << " ";
			sr.pop();
			p = p->rightchild;
		}
	}
	//后序非递归
	void unvec_back_order() {//双栈
		if (root == nullptr)return;
		std::stack<Node*>st1;
		std::stack<Node*>st2;
		Node* p = root;
		st1.push(root);
		while (!st1.empty()) {
			p = st1.top();
			st2.push(p);
			st1.pop();
			if (p->leftchild != nullptr)st1.push(p->leftchild);
			if (p->rightchild != nullptr)st1.push(p->rightchild);
		}
		while (!st2.empty()) {
			std::cout << st2.top()->val << "  ";
			st2.pop();
		}
	}
	//层序非递归
	void unvec_level_order() {
		if (root == nullptr)return;
		Node* p = root;
		std::queue<Node*>qu;
		qu.push(root);
		while (!qu.empty()) {
			p = qu.front();
			std::cout << p->val << "  ";
			qu.pop();
			if (p->leftchild != nullptr)qu.push(p->leftchild);
			if (p->rightchild != nullptr)qu.push(p->rightchild);
		}
	}
	//查找范围内的数
	void find_between(int a, int b) {
		Node* p = root;
		rec_in_order(p, a, b);
		std::cout << std::endl;
	}
	void rec_in_order(Node* p, int a, int b) {
		if (p == nullptr)return;
		if(p->val > a) rec_in_order(p->leftchild, a, b);
		if (p->val >= a && p->val <= b) std::cout << p->val << "  ";
		if(p->val < b) rec_in_order(p->rightchild, a, b);
	}
	//判断是否为BSTree
	bool is_BST() {
		Node* p = root;
		int a = INT_MIN;
		return is_BSTree(p, a);
	}
	bool is_BSTree(Node* p, int& a) {
		if (p == nullptr)return true;
		if (!is_BSTree(p->leftchild, a)) {
			return false;
		}
		if (a >= p->val)return false;
		else a = p->val;
		return is_BSTree(p->rightchild, a);
	}
	//判断是否为子树
	bool is_BST_child(Node* bst) {
		if (bst == nullptr)return true;
		Node* p = find_Node(bst->val);
		if (p == nullptr)return false;
		return rec_in_order(p, bst);
	}
	bool rec_in_order(Node* p, Node* bst) {
		if (p == nullptr && bst == nullptr)return true;
		if (p == nullptr)return false;
		if (bst == nullptr)return true;
		if (p->val != bst->val)return false;
		return rec_in_order(p->leftchild, bst->leftchild)
			&& rec_in_order(p->rightchild, bst->rightchild);
	}
	//BST树的LCA问题
	void find_father(int val1, int val2) {
		if (find_Node(val1) == nullptr || find_Node(val2) == nullptr) {
			throw "no find node!";
		}
		Node* p = root;
		std::cout << find_father(p, val1, val2)->val << std::endl;
	}
	Node* find_father(Node* p, int val1, int val2) {
		if (p == nullptr) {
			return nullptr;
		}
		if (p->val < val1 && p->val < val2) {
			return find_father(p->rightchild, val1, val2);
		}
		else if (p->val > val1 && p->val > val2) {
			return find_father(p->leftchild, val1, val2);
		}
		else {
			return p;
		}
	}
	//镜像翻转
	void BST_mirror() {
		Node* p = root;
		BST_mirror(p);
		unvec_in_order();
	}
	void BST_mirror(Node* p) {
		if (p == nullptr)return;
		Node* q = p->leftchild;
		p->leftchild = p->rightchild;
		p->rightchild = q;
		BST_mirror(p->leftchild);
		BST_mirror(p->rightchild);
	}
	//二叉树对称
	bool Tree_symmetry() {
		if (root == nullptr) {
			return true;
		}
		return Tree_symmetry(root->leftchild, root->rightchild);
	}
	bool Tree_symmetry(Node* p, Node* q) {
		if (p == nullptr && q == nullptr)return true;
		if (p == nullptr || q == nullptr)return false;
		if (p->val != q->val)return false;
		return Tree_symmetry(p->leftchild, q->rightchild)
			&& Tree_symmetry(p->rightchild, q->leftchild);
	}
	//已知前序和中序，重构二叉树
	void re_BSTree(std::vector<int>VLR, std::vector<int>LVR) {
		int num = 0;
		root = re_BSTree(VLR, LVR, 0, VLR.size() - 1, num);
		unvec_in_order();
	}
	Node* re_BSTree(std::vector<int>&VLR, std::vector<int>&LVR, int front, int last, int& num) {
		if (last < front) {
			return nullptr;
		}
		int i = 0;
		for (; i < last; i++) {
			if (LVR[i] == VLR[num]) {
				break;
			}
		}
		Node* p = new Node(VLR[num]);
		num++;
		p->leftchild = re_BSTree(VLR, LVR, front, i - 1, num);
		p->rightchild = re_BSTree(VLR, LVR, i + 1, last, num);
		return p;
	}
	//判断二叉树是否为平衡树
	bool isBalance_Tree() {
		Node* p = root;
		if (isBalance_Tree(p) == -1)return false;
		return true;
	}
	int isBalance_Tree(Node* p) {
		if (p == nullptr)return 1;
		int left = isBalance_Tree(p->leftchild);
		if (left == -1)return -1;
		int right = isBalance_Tree(p->rightchild);
		if (right == -1)return -1;
		if (abs(left - right) > 1)return -1;
		return std::max(left, right) + 1;
	}
	//中序倒数第K个节点
	void reNode(int k) {
		Node* p = root;
		int i = 1;
		std::cout << reNode(p, k, i)->val << std::endl;
	}
	Node* reNode(Node* p, int k, int& i) {
		if (p == nullptr) return nullptr;
		Node* right = reNode(p->rightchild, k, i);
		if (right != nullptr) return right;
		if (i == k) return p;
		i++;
		return reNode(p->leftchild, k, i);
	}
	//获取头节点
	Node* get_root() {
		return root;
	}
private:
	Node* root;
	int Node_num;
};

void test() {
	BSTree bs;
	std::vector<int>vecs = { 51, 32, 17, 5, 21, 38, 35, 71, 66, 69, 89 };
	std::vector<int>ve = { 5,3,7 };
	for (auto vec : vecs) {
		bs.push_Node(vec);
	}
	bs.show_inorder();
}

void test2() {
	rec_BSTree reB;
	rec_BSTree reb;
	BSTree bs;
	std::vector<int>vecs = { 51, 32, 17, 5, 21, 38, 35, 71, 66, 69, 89 };
	for (auto vec : vecs) {
		reB.push_Node(vec);
		bs.push_Node(vec);
	}
	/*std::vector<int>vec = { 71, 66, 89 };
	for (auto v : vec) {
		reb.push_Node(v);
	}
	if (reB.is_BST_child(reb.get_root())) {
		std::cout << "yes" << std::endl;
	}
	else std::cout << "no" << std::endl;
	std::cout << std::endl;
	reB.find_father(5, 17);
	std::cout << std::endl;
	reB.BST_mirror();
	std::cout << std::endl;
	reB.BST_mirror();
	std::cout << std::endl;
	reB.unvec_front_order();
	std::cout << std::endl;
	std::vector<int>in{ 5, 17, 21, 32, 35, 38, 51, 66, 69, 71, 89 };
	std::vector<int>front{ 51, 32, 17, 5, 21, 38, 35, 71, 66, 69, 89 };
	reB.re_BSTree(front, in);
	std::cout << std::endl;*/
	if (reB.isBalance_Tree() == true) {
		std::cout << "he" << std::endl;
	}
	else std::cout << "no" << std::endl;

	reB.reNode(2);
}
void test3() {
	rec_BSTree reB;
	std::vector<int>in{ 5, 17, 21, 32, 35, 38, 51, 66, 69, 71, 89 };
	std::vector<int>front{ 51, 32, 17, 5, 21, 38, 35, 71, 66, 69, 89 };
	reB.re_BSTree(front, in);
}

int main() {
	test2();
	return 0;
}