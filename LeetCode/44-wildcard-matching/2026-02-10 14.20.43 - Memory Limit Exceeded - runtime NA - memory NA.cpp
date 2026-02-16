class Solution {
public:
    bool rec(string s, string p, int i, int j) {
        if (i < 0 && j < 0)
            return true;
        if (j < 0 && i >= 0)
            return false;
        if (i < 0 && j >= 0) {
            while (j >= 0) {
                if (p[j] != '*')
                    return false;
                j--;
            }
            return true;
        }
        if (s[i] == p[j] || p[j] == '?')
            return rec(s, p, i - 1, j - 1);

        if (p[j] == '*') {
            return rec(s, p, i - 1, j) || rec(s, p, i, j - 1);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        return rec(s, p, n - 1, m - 1);
    }
};