class MyStack {
public:
    int* Queue;
    int tail;
    int size;
    MyStack(int size = 20) {
        tail = 0;
        Queue = new int[size];
    }

    ~MyStack() {
        delete[] Queue;
        Queue = nullptr;
    }

    void push(int x) {
        if (tail == 20) {
            int* p = new int[2 * size];
            memcpy(p, Queue, 2 * size * sizeof(int));
            delete Queue;
            Queue = p;
        }
        Queue[tail] = x;
        tail++;
    }

    int pop() {
        tail--;
        return Queue[tail];
    }

    int top() {
        return Queue[tail - 1];
    }

    bool empty() {
        return tail == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */