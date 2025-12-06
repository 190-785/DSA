class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10)
            return false;
        int temp = n;
        bool Alice = false;
        temp -= 10;
        while (temp) {
            if (Alice) {
                temp--;
                Alice = false;
            } else {
                temp--;
                Alice = true;
            }
        }
        return !Alice;
    }
};