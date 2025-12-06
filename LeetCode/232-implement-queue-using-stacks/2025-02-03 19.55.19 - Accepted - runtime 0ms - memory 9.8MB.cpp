class MyQueue {
private:
    stack<int> stk1;
    stack<int> stk2;

public:
    MyQueue() {
    }

    void push(int x) {
        while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk1.push(x);
        while (!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }

    int pop() {
        if (stk1.empty()) {
            return -1; 
        }
        int ele = stk1.top();
        stk1.pop();
        return ele;
    }

    int peek() {
        if (stk1.empty()) {
            return -1;
        }
        return stk1.top();
    }

    bool empty() {
        return stk1.empty();
    }
};
