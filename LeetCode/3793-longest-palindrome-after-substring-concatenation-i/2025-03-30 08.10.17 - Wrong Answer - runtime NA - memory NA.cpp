class Solution {
public:
    bool isPalindrome(string str) {
        int left = 0, right = str.length() - 1;
        while (left < right) {
            if (str[left++] != str[right--]) {
                return false;
            }
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        int maxL = 0;
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                string conc = s.substr(0, i) + t.substr(j);
                if (isPalindrome(conc)) {
                    maxL = max(maxL, (int)conc.size());
                }
            }
        }
        return maxL;
    }
};