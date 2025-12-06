class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m - k + 1, vector<int>(n - k + 1, 0));
        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                vector<int> values;
                for (int r = i; r < i + k; r++)
                    for (int c = j; c < j + k; c++)
                        values.push_back(grid[r][c]);
                sort(values.begin(), values.end());
                int diff = INT_MAX;
                for (int p = 1; p < values.size(); p++) {
                    if (values[p] != values[p - 1])
                        diff = min(diff, values[p] - values[p - 1]);
                }
                res[i][j] = (diff == INT_MAX) ? 0 : diff;
            }
        }
        return res;
    }
};
