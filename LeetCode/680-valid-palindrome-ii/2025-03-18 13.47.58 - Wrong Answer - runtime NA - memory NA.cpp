class Solution {
public:
    bool validPalindrome(string s) {
        int canBe = 0;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                if (canBe == 1)
                    return false;
                canBe++;
            }
            i++, j--;
        }
        if (canBe == 1 && s.size() % 2 != 0)
            return false;
        return true;
    }
};