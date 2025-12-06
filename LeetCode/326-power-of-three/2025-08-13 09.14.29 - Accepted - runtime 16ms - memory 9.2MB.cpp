class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1) return false;
        if (n == 1 || n == 3)
            return true;
        int low = 0;
        int high = n / 3;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (pow(3, mid) == n) {
                return true;
            } else if (pow(3, mid) > n) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};