class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x;
        int res = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if ((long long)mid * mid == x) {
                return mid;
            } else if ((long long)mid * mid < x) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};
