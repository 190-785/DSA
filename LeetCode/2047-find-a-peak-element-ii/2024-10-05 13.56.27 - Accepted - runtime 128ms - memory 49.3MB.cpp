class Solution {
public:
    int findMax(vector<vector<int>>& mat, int mid) {
        int n = mat.size();
        int maxE = INT_MIN;
        int maxI = 0;
        for (int i = 0; i < n; i++) {
            if (mat[i][mid] > maxE) {
                maxE = mat[i][mid];
                maxI = i;
            }
        }
        return maxI;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int col = mat[0].size();
        int start = 0;
        int end = col - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            int maxi = findMax(mat, mid);
            int left = (mid - 1 >= 0) ? mat[maxi][mid - 1] : -1;
            int right = (mid + 1 < col) ? mat[maxi][mid + 1] : -1;
            if (mat[maxi][mid] > left && mat[maxi][mid] > right) {
                return {maxi, mid};
            } else if (mat[maxi][mid] <= left) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return {-1, -1};
    }
};