class Solution {
public:
    int i = 0;
    bool isPalindrome(string s) {
        int size = s.size();
        while (i < size) {
            if (!isalnum(s[i])) {
                i++;
            } else if (!isalnum(s[size - 1])) {
                size--;
            } else {
                if (tolower(s[i]) != tolower(s[size - 1])) {
                    return false;
                }
                i++;
                size--;
            }
        }
        return true;
    }
};
