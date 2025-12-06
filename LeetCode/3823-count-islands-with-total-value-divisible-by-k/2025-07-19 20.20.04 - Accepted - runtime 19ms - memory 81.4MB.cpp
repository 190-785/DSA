class Solution {
public:
    long long dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited,
                  int n, int m) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (n < 0 || n >= rows || m < 0 || m >= cols || visited[n][m] ||
            grid[n][m] == 0) {
            return 0;
        }
        visited[n][m] = true;
        long long currSum = grid[n][m];
        currSum += dfs(grid, visited, n + 1, m);
        currSum += dfs(grid, visited, n - 1, m);
        currSum += dfs(grid, visited, n, m + 1);
        currSum += dfs(grid, visited, n, m - 1);
        return currSum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int validI = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0 && !visited[i][j]) {
                    long long Sum = dfs(grid, visited, i, j);
                    if (Sum % k == 0) {
                        validI++;
                    }
                }
            }
        }
        return validI;
    }
};