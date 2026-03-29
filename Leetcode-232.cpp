//²»Ñ­»·Ë³ÐòÕ»
class MyQueue {
public:
    int* intstack;
    int* outstack;
    int out_head, out_top, in_head, in_top;
    MyQueue() {
        intstack = new int[100];
        in_top = 0;
        outstack = new int[100];
        out_top = 0;
        return;
    }

    void push(int x) {
        intstack[in_top] = x;
        in_top++;
    }

    int pop() {
        if (out_top == 0) {
            while (in_top > 0) {
                in_top--;
                outstack[out_top] = intstack[in_top];
                out_top++;
            }
        }
        out_top--;
        return outstack[out_top];
    }

    int peek() {
        if (out_top == 0) {
            while (in_top > 0) {
                in_top--;
                outstack[out_top] = intstack[in_top];
                out_top++;
            }
        }
        return outstack[out_top - 1];
    }

    bool empty() { return in_top == 0 && out_top == 0; }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

//STLÕ»
class MyQueue {
public:
    std::stack<int> instack;
    std::stack<int> outstack;
    MyQueue() {}

    void push(int x) { instack.push(x); }

    int pop() {
        if (outstack.empty()) {
            while (!instack.empty()) {
                outstack.push(instack.top());
                instack.pop();
            }
        }
        int i = outstack.top();
        outstack.pop();
        return i;
    }

    int peek() {
        if (outstack.empty()) {
            while (!instack.empty()) {
                outstack.push(instack.top());
                instack.pop();
            }
        }
        return outstack.top();
    }

    bool empty() { return outstack.empty() && instack.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */