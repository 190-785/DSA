class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        string result;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (depth > 0) {
                    result += s[i];
                }
                depth++;
            } else {
                depth--;
                if (depth > 0) {
                    result += s[i];
                }
            }
        }
        return result;
    }
};