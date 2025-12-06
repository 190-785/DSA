class Solution {
public:
    int minLength(string s) {
        stack<char> subStr;
        for (char c : s) {
            if ((c == 'B' && !subStr.empty() && subStr.top() == 'A') ||
                (c == 'D' && !subStr.empty() && subStr.top() == 'C')) {
                subStr.pop();
            } else {
                subStr.push(c);
            }
        }
        return subStr.size();
    }
};
