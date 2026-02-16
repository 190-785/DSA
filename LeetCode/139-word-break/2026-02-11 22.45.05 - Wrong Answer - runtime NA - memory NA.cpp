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
    vector<int> strStr(string haystack, string needle) {
        if (haystack == needle)
            return {};
        int n = haystack.size();
        int m = needle.size();
        string s = needle + '$' + haystack;
        vector<int> lps(n + m + 1, 0);
        createLPS(s, lps);
        // for (int i = 0; i < n; i++) cout << lps[i] << " ";
        vector<int> res;
        for (int i = m + 1; i <= m + n; i++) {
            if (lps[i] == m)
                res.push_back((i - 2 * m));
        }
        return res;
    }
    vector<int> search(string pat, string txt) { return strStr(txt, pat); }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<int>> posMap;
        int n = s.size();
        for (int i = 0; i < wordDict.size(); i++) {
            vector<int> curr = search(s, wordDict[i]);
            posMap[wordDict[i]] = curr;
        }

        return false;
    }
};