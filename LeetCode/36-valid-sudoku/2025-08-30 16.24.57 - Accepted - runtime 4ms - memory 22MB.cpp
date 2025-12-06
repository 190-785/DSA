class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;

        for (int i = 0; i < n; i++) {
            vector<bool> row(10, false), column(10, false);
            for (int j = 0; j < n; j++) {
                char currRow = board[i][j];
                if (currRow != '.') {
                    int val = currRow - '0';
                    if (row[val]) return false;
                    row[val] = true;
                }

                char currCol = board[j][i];
                if (currCol != '.') {
                    int val = currCol - '0';
                    if (column[val]) return false;
                    column[val] = true;
                }
            }
        }

        for (int boxRow = 0; boxRow < 3; boxRow++) {
            for (int boxCol = 0; boxCol < 3; boxCol++) {
                vector<bool> box(10, false);
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char curr = board[boxRow * 3 + i][boxCol * 3 + j];
                        if (curr != '.') {
                            int val = curr - '0';
                            if (box[val]) return false;
                            box[val] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};
