class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        for (char c : expression) {
            if (c == ',')
                continue;
            if (c == 't' || c == 'f' || c == '!' || c == '&' || c == '|' ||
                c == '(') {
                stk.push(c);
            } else if (c == ')') {
                vector<char> subExpr;
                while (!stk.empty() && stk.top() != '(') {
                    subExpr.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
                char op = stk.top();
                stk.pop();
                char result;
                if (op == '&') {
                    result = 't';
                    for (char val : subExpr) {
                        if (val == 'f') {
                            result = 'f';
                            break;
                        }
                    }
                } else if (op == '|') {
                    result = 'f';
                    for (char val : subExpr) {
                        if (val == 't') {
                            result = 't';
                            break;
                        }
                    }
                } else if (op == '!') {
                    result = (subExpr[0] == 't') ? 'f' : 't';
                }
                stk.push(result);
            }
        }
        return stk.top() == 't';
    }
};
