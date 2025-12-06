class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10)
            return false;
        
        int temp = n;
        bool Alice = false;
        temp -= 10;
        int removal = 9;
        
        while (temp >= 0) {
            if (Alice) {
                if (temp < removal) return false;
                temp -= removal;
                removal--;
            } else {
                if (temp < removal) return true;
                temp -= removal;
                removal--;
            }
            Alice = !Alice;
        }
        
        return false;
    }
};
