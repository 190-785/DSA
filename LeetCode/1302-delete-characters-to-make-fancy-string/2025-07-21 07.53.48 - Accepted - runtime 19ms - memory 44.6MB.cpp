class Solution {
public:
    string makeFancyString(string s) {
        string res;
        int count = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (i > 1 && s[i] == s[i - 1] && s[i] == s[i - 2]) {
                continue;
            }
            res += s[i];
        }

        return res;
    }
};
