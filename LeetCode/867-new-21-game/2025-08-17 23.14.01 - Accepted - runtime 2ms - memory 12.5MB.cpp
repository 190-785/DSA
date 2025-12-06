class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) 
            return 1.0;

        vector<double> dp(n + 1, 0.0);
        double windowSum = 0.0;

        for (int i = k; i <= n; i++) {
            dp[i] = 1.0;
        }
        //start at score->prob
        windowSum = min(n - k + 1, maxPts);

        for (int i = k - 1; i >= 0; i--) {
            dp[i] = windowSum / maxPts;
            windowSum += dp[i];
            if (i + maxPts <= n) {
                windowSum -= dp[i + maxPts];
            }
        }

        return dp[0];
    }
};
