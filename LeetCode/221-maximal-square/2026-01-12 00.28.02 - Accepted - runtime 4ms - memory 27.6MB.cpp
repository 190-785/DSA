class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        int maxSqs = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i - 1][j - 1] == '1'){
                    curr[j] = min({prev[j], prev[j - 1], curr[j - 1]}) + 1;
                maxSqs = max(maxSqs, curr[j]);
                }
                else curr[j]=0;
            }
            prev = curr;
        }
        return maxSqs * maxSqs;
    }
};