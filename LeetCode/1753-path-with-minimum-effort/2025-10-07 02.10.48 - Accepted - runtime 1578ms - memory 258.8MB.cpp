class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int m, n;
    bool dfs(int r, int c, int mid, vector<vector<bool>>& visited,
             const vector<vector<int>>& heights) {
        if (r == m - 1 && c == n - 1)
            return true;
        visited[r][c] = true;
        for (auto dir : directions) {
            int x = dir[0] + r;
            int y = dir[1] + c;
            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                if (abs(heights[x][y] - heights[r][c]) <= mid) {
                    if (dfs(x, y, mid, visited, heights))
                        return true;
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        int low = 0;
        int high = 1000000;
        high--;
        while (low < high) {
            int mid = low + (high - low) / 2;
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            if (dfs(0, 0, mid, visited, heights))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};