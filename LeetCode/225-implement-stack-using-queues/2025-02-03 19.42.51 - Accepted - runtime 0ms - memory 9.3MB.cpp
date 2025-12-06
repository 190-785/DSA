class MyStack {
private:
    queue<int> q;

public:
    MyStack() {
    }

    void push(int x) {
        q.push(x);
        for (int i = 1; i < q.size(); i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) {
            return -1; 
        }
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    int top() {
        if (q.empty()) {
            return -1; 
        }
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
