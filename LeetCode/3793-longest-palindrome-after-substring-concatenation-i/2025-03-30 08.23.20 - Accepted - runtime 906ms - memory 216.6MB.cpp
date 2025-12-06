class Solution {
public:
    bool isPalindrome(const string &str) {
        int l = 0, r = str.size() - 1;
        while(l < r) {
            if(str[l++] != str[r--])
                return false;
        }
        return true;
    }
    
    int longestPalindrome(string s, string t) {
        int ans = 0;
        int n = s.size(), m = t.size();
        for (int i = 0; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                string subS = s.substr(i, j - i);
                for (int p = 0; p <= m; p++) {
                    for (int q = p; q <= m; q++) {
                        string subT = t.substr(p, q - p);
                        string candidate = subS + subT;
                        if (isPalindrome(candidate))
                            ans = max(ans, (int)candidate.size());
                    }
                }
            }
        }
        return ans;
    }
};
