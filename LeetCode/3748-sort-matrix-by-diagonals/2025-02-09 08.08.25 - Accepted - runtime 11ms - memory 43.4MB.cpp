class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        for (int i = 0; i < n; i++) {
            vector<int> diag;
            int x = i, y = 0;
            while (x < n && y < n) {
                diag.push_back(grid[x][y]);
                x++;
                y++;
            }
            sort(diag.begin(), diag.end(), greater<int>());
            x = i, y = 0;
            int idx = 0;
            while (x < n && y < n) {
                grid[x][y] = diag[idx++];
                x++;
                y++;
            }
        }
        
        for (int j = 1; j < n; j++) {
            vector<int> diag;
            int x = 0, y = j;
            while (x < n && y < n) {
                diag.push_back(grid[x][y]);
                x++;
                y++;
            }
            sort(diag.begin(), diag.end());
            
            x = 0, y = j;
            int idx = 0;
            while (x < n && y < n) {
                grid[x][y] = diag[idx++];
                x++;
                y++;
            }
        }
        return grid;
    }
};
