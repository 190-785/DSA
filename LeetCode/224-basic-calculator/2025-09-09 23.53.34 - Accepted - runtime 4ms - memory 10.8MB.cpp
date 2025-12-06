class Solution {
public:
    int calculate(string s) {
        int result = 0, sign = 1, num = 0;
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;
                num = 0;
                result *= stk.top(); stk.pop();
                result += stk.top(); stk.pop();
            }
        }
        result += sign * num;
        return result;
    }
};
