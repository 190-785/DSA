class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> rowSum(m, 0), colSum(n, 0);
        long long total = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                long long v = grid[i][j];
                rowSum[i] += v;
                colSum[j] += v;
                total += v;
            }
        }
        if (total & 1LL)
            return false;
        long long half = total / 2;
        long long acc = 0;
        for (int i = 0; i < m - 1; ++i) {
            acc += rowSum[i];
            if (acc == half)
                return true;
        }
        acc = 0;
        for (int j = 0; j < n - 1; ++j) {
            acc += colSum[j];
            if (acc == half)
                return true;
        }
        return false;
    }
};
