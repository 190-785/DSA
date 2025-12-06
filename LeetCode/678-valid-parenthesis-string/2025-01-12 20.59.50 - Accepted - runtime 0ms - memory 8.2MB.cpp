class Solution {
public:
    bool checkValidString(string s) {
        int balance = 0, starBalance = 0;
        for (char c : s) {
            if (c == '(') {
                balance++;
                starBalance++;
            } else if (c == ')') {
                if (balance > 0)
                    balance--;
                starBalance--;
            } else {
                if (balance > 0)
                    balance--;
                starBalance++;
            }
            if (starBalance < 0)
                return false;
        }
        return balance == 0;
    }
};
