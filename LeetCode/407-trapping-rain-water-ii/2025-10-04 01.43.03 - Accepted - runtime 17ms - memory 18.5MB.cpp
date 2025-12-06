class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty())
            return 0;
        int rows = heightMap.size();
        int cols = heightMap[0].size();
        if (rows < 3 || cols < 3)
            return 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        for (int i = 0; i < rows; ++i) {
            pq.push({heightMap[i][0], i, 0});
            visited[i][0] = true;
            pq.push({heightMap[i][cols - 1], i, cols - 1});
            visited[i][cols - 1] = true;
        }
        for (int j = 1; j < cols - 1; ++j) {
            pq.push({heightMap[0][j], 0, j});
            visited[0][j] = true;
            pq.push({heightMap[rows - 1][j], rows - 1, j});
            visited[rows - 1][j] = true;
        }
        int result = 0;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!pq.empty()) {
            auto [height, x, y] = pq.top();
            pq.pop();
            for (auto& d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
                    !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    if (height > heightMap[nx][ny])
                        result += height - heightMap[nx][ny];
                    pq.push({max(heightMap[nx][ny], height), nx, ny});
                }
            }
        }
        return result;
    }
};
