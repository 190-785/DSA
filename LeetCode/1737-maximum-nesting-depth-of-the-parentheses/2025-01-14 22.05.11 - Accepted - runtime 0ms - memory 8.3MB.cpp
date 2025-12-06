class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        int depth = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                depth++;
                maxDepth = max(maxDepth, depth);
            } else if (s[i] == ')') {
                depth--;
            }
        }
        return maxDepth;
    }
};