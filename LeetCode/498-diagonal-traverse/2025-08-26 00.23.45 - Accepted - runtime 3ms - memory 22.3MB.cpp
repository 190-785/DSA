class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty())
            return {};

        int n = mat.size();
        int m = mat[0].size();
        int row = 0, column = 0;
        int direction = 1;
        vector<int> res(n * m);
        int idx = 0;

        while (row < n && column < m) {
            res[idx++] = mat[row][column];
            int new_row = row + (direction == 1 ? -1 : 1);
            int new_col = column + (direction == 1 ? 1 : -1);

            if (new_row < 0 || new_row == n || new_col < 0 || new_col == m) {
                if (direction == 1) {
                    row += (column == m - 1 ? 1 : 0);
                    column += (column < m - 1 ? 1 : 0);
                } else {
                    column += (row == n - 1 ? 1 : 0);
                    row += (row < n - 1 ? 1 : 0);
                }
                direction = 1 - direction;
            } else {
                row = new_row;
                column = new_col;
            }
        }
        return res;
    }
};
