class Solution {
public:
    bool isPalindrome(const string &str) {
        int l = 0, r = str.size() - 1;
        while(l < r) {
            if(str[l] != str[r])
                return false;
            l++; r--;
        }
        return true;
    }
    
    int longestPalSubstr(const string &s) {
        int n = s.size(), maxLen = 0;
        for(int i = 0; i < n; i++){
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                maxLen = max(maxLen, r - l + 1);
                l--; r++;
            }
            l = i, r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                maxLen = max(maxLen, r - l + 1);
                l--; r++;
            }
        }
        return maxLen;
    }
    
    int longestPalindrome(string s, string t) {
        int ans = max(longestPalSubstr(s), longestPalSubstr(t));
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string X = s.substr(i, j - i + 1);
                for (int k = 1; k <= X.size(); k++) {
                    string U = X.substr(0, k);
                    string V = X.substr(k);
                    if (!isPalindrome(V))
                        continue;
                    string revU = U;
                    reverse(revU.begin(), revU.end());
                    if (t.find(revU) != string::npos)
                        ans = max(ans, 2 * k + (int)V.size());
                }
            }
        }
        return ans;
    }
};
