class Solution {
public:
    string reverseWords(string s) {
        string result;
        int start = -1;
        int end = -1;
        int n = s.size() - 1;

        for (int i = n; i >= 0; i--) {
            if (s[i] != ' ') {
                if (end < 0)
                    end = i;
                start = i;
            } else {
                if (end >= 0) {
                    if (!result.empty())
                        result += ' ';
                    result += s.substr(start, end - start + 1);
                    end = -1;
                }
            }
        }

        if (end >= 0) {
            if (!result.empty())
                result += ' ';
            result += s.substr(start, end - start + 1);
        }

        return result;
    }
};
