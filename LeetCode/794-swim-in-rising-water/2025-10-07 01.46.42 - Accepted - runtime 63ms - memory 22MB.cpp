class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int n, m;
    bool dfs(int r, int c, int mid, vector<vector<bool>>& visited,
             vector<vector<int>>& grid) {
        if (r == m - 1 && c == n - 1)
            return true;
        visited[r][c] = true;
        for (auto dir : directions) {
            int x = dir[0] + r;
            int y = dir[1] + c;
            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                if (grid[x][y] <= mid) {
                    if (dfs(x, y, mid, visited, grid))
                        return true;
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int low = grid[0][0];
        int high = 0;
        for (auto& row : grid) {
            for (int val : row)
                high = max(high, val);
        }
        while (low < high) {
            int mid = low + (high - low) / 2;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            if (dfs(0, 0, mid, visited, grid)) {
                high = mid;
            } else
                low = mid + 1;
        }
        return low;
    }
};