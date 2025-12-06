class Solution {
public:
    void dfs(int i, int j, int xorValue, vector<vector<int>>& grid, int k,
             int& result, int MOD) {
        if (i >= grid.size() || j >= grid[0].size())
            return;
        xorValue ^= grid[i][j];
        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            if (xorValue == k)
                result = (result + 1) % MOD;
            return;
        }

        dfs(i + 1, j, xorValue, grid, k, result, MOD);
        dfs(i, j + 1, xorValue, grid, k, result, MOD);
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;
        int result = 0;
        dfs(0, 0, 0, grid, k, result, MOD);
        return result;
    }
};
