class Solution {
public:
    string clearDigits(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (!isdigit(s[i])) {
                stk.push(s[i]);
            } else {
                if (!stk.empty()) {
                    stk.pop();
                }
            }
        }
        string res;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
