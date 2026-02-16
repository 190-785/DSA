class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n < 2)
            return 0;
        stack<char> stk;
        int res = 0;
        stk.push(s[0]);
        int curr = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == '(') {
                stk.push(s[i]);
                continue;
            }
            if (!stk.empty()) {
                char prev = stk.top();
                if (prev == '(') {
                    curr++;
                    res = max(curr, res);
                    stk.pop();
                } else {
                    curr = 0;
                    while (!stk.empty())
                        stk.pop();
                }
            }
        }
        return res * 2;
    }
};