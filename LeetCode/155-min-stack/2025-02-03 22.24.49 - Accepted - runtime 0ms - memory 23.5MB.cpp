class MinStack {
private:
    long long mini = LLONG_MAX;
    stack<long long> stk;

public:
    MinStack() {}

    void push(int val) {
        long long value = static_cast<long long>(val);
        if (stk.empty()) {
            stk.push(value);
            mini = value;
        } else {
            if (value >= mini) {
                stk.push(value);
            } else {
                long long nval = 2 * value - mini;
                stk.push(nval);
                mini = value;
            }
        }
    }

    void pop() {
        if (stk.top() >= mini) {
            stk.pop();
        } else {
            long long pmin = 2 * mini - stk.top();
            mini = pmin;
            stk.pop();
        }
    }

    int top() {
        if (stk.top() >= mini) {
            return static_cast<int>(stk.top());
        } else {
            return static_cast<int>(mini);
        }
    }

    int getMin() {
        return static_cast<int>(mini);
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */