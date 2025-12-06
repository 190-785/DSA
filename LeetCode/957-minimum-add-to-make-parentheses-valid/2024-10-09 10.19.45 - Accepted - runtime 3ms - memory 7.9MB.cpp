class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stackStr;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')') {
                if (!stackStr.empty() && stackStr.top() == '(') {
                    stackStr.pop();
                } else {
                    stackStr.push(s[i]);
                }
            } else {
                stackStr.push(s[i]);
            }
        }
        return stackStr.size();
    }
};