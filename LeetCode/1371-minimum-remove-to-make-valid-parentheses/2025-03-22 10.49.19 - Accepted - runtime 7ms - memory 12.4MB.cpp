class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int right = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            if (c == '(') {
                if (right == 0) {
                    s.erase(s.begin() + i);
                } else {
                    right--;
                }
            } else if (c == ')') {
                right++;
            }
        }

        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == ')') {
                if (left == 0) {
                    s.erase(s.begin() + i);
                    i--;
                } else {
                    left--;
                }
            } else if (c == '(') {
                left++;
            }
        }

        return s;
    }
};
