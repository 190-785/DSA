class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n & (n - 1))
            return false;
        return true;
    }
};