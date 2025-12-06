class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> check(n, vector<bool>(m, false));
        queue<pair<int, int>> rotten;
        int fresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    check[i][j] = true;
                    rotten.push({i, j});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int time = 0;

        while (!rotten.empty() && fresh > 0) {
            int len = rotten.size();
            while (len--) {
                pair<int, int> p = rotten.front();
                rotten.pop();
                int x = p.first;
                int y = p.second;
                if (x > 0 && grid[x - 1][y] == 1 && !check[x - 1][y]) {
                    check[x - 1][y] = true;
                    grid[x - 1][y] = 2;
                    rotten.push({x - 1, y});
                    fresh--;
                }
                if (x < n - 1 && grid[x + 1][y] == 1 && !check[x + 1][y]) {
                    check[x + 1][y] = true;
                    grid[x + 1][y] = 2;
                    rotten.push({x + 1, y});
                    fresh--;
                }
                if (y > 0 && grid[x][y - 1] == 1 && !check[x][y - 1]) {
                    check[x][y - 1] = true;
                    grid[x][y - 1] = 2;
                    rotten.push({x, y - 1});
                    fresh--;
                }
                if (y < m - 1 && grid[x][y + 1] == 1 && !check[x][y + 1]) {
                    check[x][y + 1] = true;
                    grid[x][y + 1] = 2;
                    rotten.push({x, y + 1});
                    fresh--;
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};
