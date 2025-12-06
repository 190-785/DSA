class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 1)
            return false;
        int maxNum = 1;
        // Since in powers of 2 we get them at every bit
        // But for the powers of 4 we only get them at every other bit
        while (maxNum <= n) {
            if (maxNum == n)
                return true;
            maxNum = maxNum << 2;
        }
        return false;
    }
};