class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> area(m, vector<int>(n, -1));
        for (auto& guard : guards) {
            int x = guard[0];
            int y = guard[1];

            area[x][y] = 1;
        }

        for (auto& wall : walls) {
            int x = wall[0];
            int y = wall[1];

            area[x][y] = 0;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (area[i][j] == 1) {
                    while (j < n && area[i][j]) {

                        if (area[i][j] != 1)
                            area[i][j] = 2;
                        j++;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (area[i][j] == 1) {
                    while (j >= 0 && area[i][j]) {

                        if (area[i][j] != 1)
                            area[i][j] = 2;
                        j--;
                    }
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = m - 1; i >= 0; i--) {
                if (area[i][j] == 1) {
                    while (i >= 0 && area[i][j]) {
                        if (area[i][j] != 1)
                            area[i][j] = 2;
                        i--;
                    }
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (area[i][j] == 1) {
                    while (i < m && area[i][j]) {
                        if (area[i][j] != 1)
                            area[i][j] = 2;
                        i++;
                    }
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (area[i][j] == -1) {
                    res++;
                }
            }
        }

        return res;
    }
};