class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int up = matrix[i][j] + dp[i - 1][j];
                int leftd = 1e9;
                int rightd = 1e9;
                if (j - 1 >= 0) {
                    leftd = matrix[i][j] + dp[i - 1][j - 1];
                }
                if (j + 1 < m) {
                    rightd = matrix[i][j] + dp[i - 1][j + 1];
                }
                dp[i][j] = min(up, min(leftd, rightd));
            }
        }
        int mini = dp[n - 1][0];
        for (int i = 1; i < m; i++) {
            mini = min(mini, dp[n - 1][i]);
        }
        return mini;
    }
};