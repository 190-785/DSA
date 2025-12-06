class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (j == 0)
                    temp[j] = dp[j];
                else
                    temp[j] = dp[j] + temp[j - 1];
            }
            dp = temp;
        }
        return dp[n - 1];
    }
};
