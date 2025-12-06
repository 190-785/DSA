class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, maxLength = 0;
        
        for (int i = 0; i < s.size(); i++) {
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left - 1 > maxLength) {
                start = left + 1;
                maxLength = right - left - 1;
            }
            left = i, right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            if (right - left - 1 > maxLength) {
                start = left + 1;
                maxLength = right - left - 1;
            }
        }
        return s.substr(start, maxLength);
    }
};
