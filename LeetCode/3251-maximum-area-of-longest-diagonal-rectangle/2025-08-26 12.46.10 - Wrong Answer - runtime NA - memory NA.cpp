class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int diagonalLen = 0;
        int area = 0;
        for (int i = 0; i < n; i++) {
            int Length = dimensions[i][0];
            int Width = dimensions[i][1];
            int diagLen = sqrt((Length * Length) + (Width * Width));
            if (diagonalLen < diagLen) {
                diagonalLen = diagLen;
                area = Length * Width;
            }
            if (diagonalLen == diagLen) {
                if (area < Length * Width) {
                    diagonalLen = diagLen;
                    area = Length * Width;
                }
            }
        }
        return area;
    }
};