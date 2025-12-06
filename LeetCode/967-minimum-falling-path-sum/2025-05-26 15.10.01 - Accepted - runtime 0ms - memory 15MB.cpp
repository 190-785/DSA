class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m);
        for (int j = 0; j < m; j++) {
            prev[j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++) {
            vector<int> curr(m);
            for (int j = 0; j < m; j++) {
                int up = matrix[i][j] + prev[j];
                int leftd = 1e9;
                int rightd = 1e9;
                if (j - 1 >= 0) {
                    leftd = matrix[i][j] + prev[j - 1];
                }
                if (j + 1 < m) {
                    rightd = matrix[i][j] + prev[j + 1];
                }
                curr[j] = min(up, min(leftd, rightd));
            }
            prev = curr;
        }
        int mini = prev[0];
        for (int i = 1; i < m; i++) {
            mini = min(mini, prev[i]);
        }
        return mini;
    }
};