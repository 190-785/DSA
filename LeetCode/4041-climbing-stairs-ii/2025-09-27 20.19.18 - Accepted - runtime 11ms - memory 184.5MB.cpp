class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        const long long INF = 9e18;
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = max(0, i - 3); j < i; j++) {
                long long jump = static_cast<long long>(i - j) * (i - j);
                long long step = costs[i - 1];
                dp[i] = min(dp[i], dp[j] + step + jump);
            }
        }
        return static_cast<int>(dp[n]);
    }
};