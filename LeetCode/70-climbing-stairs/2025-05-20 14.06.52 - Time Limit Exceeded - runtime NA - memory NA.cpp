class Solution {
public:
    int dp(int idx) {
        if (idx == 0)
            return 1;
        if (idx == 1)
            return 1;
        int left = dp(idx - 1);
        int right = dp(idx - 2);
        return left + right;
    }
    int climbStairs(int n) { return dp(n); }
};