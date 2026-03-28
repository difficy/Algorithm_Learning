class Solution {
    //用STL栈解决
public:
    bool isValid(string s) {
        std::stack<char>ca;
        if (s.size() % 2 != 0)
            return false;
        for (auto s : s) {
            if (s == '(' || s == '{' || s == '[') {
                ca.push(s);
            }
            else {
                if (ca.empty())
                    return false;
                char a = ca.top();
                if ((a == '(' && s == ')') || (a == '[' && s == ']') ||
                    (a == '{' && s == '}')) {
                    ca.pop();
                }
                else {
                    return false;
                }
            }
        }
        if (ca.empty()) {
            return true;
        }
        return false;
    }
};
//用顺序栈
class Solution {
public:
    Solution() { head = new ListNode(); }
    ~Solution() {
        ListNode* p = head;
        while (p != nullptr) {
            head = head->next;
            delete p;
            p = head;
        }
    }
    void push(char a) {
        ListNode* node = new ListNode(a);
        node->next = head->next;
        head->next = node;
    }
    void pop() {
        ListNode* p = head->next;
        head->next = p->next;
        delete p;
        p = nullptr;
    }
    char top() {
        if (head->next == nullptr) {
            return false;
        }
        return head->next->arr;
    }
    bool empty() { return head->next == nullptr; }
    bool isValid(string s) {
        if (s.size() % 2 != 0) { return false; }
        for (char s : s) {
            if (s == '(' || s == '{' || s == '[') {
                push(s);
            }
            else {
                if (empty()) return false;
                char as = top();
                if ((as == '(' && s == ')') ||
                    (as == '{' && s == '}') ||
                    (as == '[' && s == ']')) {
                    pop();
                }
                else {
                    return false;
                }
            }
        }
        if (empty()) {
            return true;
        }
        return false;
    }

private:

    struct ListNode {
        char arr;
        ListNode* next;
        ListNode(char ar = 'a') : arr(ar), next(nullptr) {}
    };
    ListNode* head;
};