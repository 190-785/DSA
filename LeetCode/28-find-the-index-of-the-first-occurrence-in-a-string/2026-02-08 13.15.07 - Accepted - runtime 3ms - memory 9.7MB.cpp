class Solution {
public:
    void createLPS(string s, vector<int>& lps) {
        int j = 0, i = 1;
        int n = s.size();
        while (i < n) {
            if (s[i] == s[j]) {
                lps[i] = j + 1;
                i++, j++;
            } else {
                while (j > 0 && s[j] != s[i])
                    j = lps[j - 1];
                if (s[j] == s[i]) {
                    lps[i] = j + 1;
                    j++;
                }
                i++;
            }
        }
        return;
    }
    int strStr(string haystack, string needle) {
        if (haystack == needle)
            return 0;
        int n = haystack.size();
        int m = needle.size();
        string s = needle + '$' + haystack;
        vector<int> lps(n + m + 1, 0);
        createLPS(s, lps);
        // for (int i = 0; i < n; i++)
        // cout << lps[i] << " ";

        for (int i = m + 1; i <= m + n; i++) {
            if (lps[i] == m)
                return (i - 2 * m);
        }
        return -1;
    }
};