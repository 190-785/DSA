class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (t.size() < s.size())
            return false;
        int n = t.size();
        int j = 0;
        int m = s.size();
        for (int i = 0; i < n; i++) {
            if (s[j] == t[i]) {
                j++;
                if (j >= m)
                    break;
            }
        }
        return (j >= m)? true:false;
    }
};