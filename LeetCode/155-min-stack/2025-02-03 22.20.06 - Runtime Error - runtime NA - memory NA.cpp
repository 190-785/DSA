class MinStack {
private:
    int mini = INT_MAX;
    stack<int> stk;

public:
    MinStack() {}

    void push(int val) {
        if (stk.empty()) {
            stk.push(val);
            mini = val;
        } else {
            if (val >= mini)
                stk.push(val);
            else {
                int nval = 2 * val - mini;
                stk.push(nval);
                mini = val;
            }
        }
    }

    void pop() {
        if (stk.top() > mini)
            stk.pop();
        else {
            int pmin = 2 * mini - stk.top();
            mini = pmin;
            stk.pop();
        }
    }

    int top() {
        if (stk.top() > mini)
            return stk.top();
        return mini;
    }

    int getMin() { return mini; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */