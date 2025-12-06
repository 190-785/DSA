class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int maxValue = m * n;
        vector<pair<int, int>> positions(maxValue + 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                positions[mat[i][j]] = {i, j};
            }
        }
        vector<int> rowCount(m, 0), colCount(n, 0);
        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            int row = positions[num].first;
            int col = positions[num].second;
            rowCount[row]++;
            colCount[col]++;
            if (rowCount[row] == n || colCount[col] == m) {
                return i;
            }
        }

        return -1;
    }
};
