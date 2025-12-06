class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> prefixSumTop(n, 0), prefixSumBottom(n, 0);
        prefixSumTop[0] = grid[0][0];
        prefixSumBottom[0] = grid[1][0];
        for (int i = 1; i < n; ++i) {
            prefixSumTop[i] = prefixSumTop[i - 1] + grid[0][i];
            prefixSumBottom[i] = prefixSumBottom[i - 1] + grid[1][i];
        }
        
        long long result = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            long long topRemaining = prefixSumTop[n - 1] - prefixSumTop[i];
            long long bottomCollected = (i > 0) ? prefixSumBottom[i - 1] : 0;
            result = min(result, max(topRemaining, bottomCollected));
        }
        
        return result;
    }
};
