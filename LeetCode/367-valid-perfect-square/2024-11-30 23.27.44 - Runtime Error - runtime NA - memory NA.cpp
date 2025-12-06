class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1)
            return true;
        int low = 1;
        int high = num / 2;
        long long res = 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            res = mid * mid;
            if (res == num)
                return true;
            else if (res < num)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};