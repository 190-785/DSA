class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int start = 0;
        int end = rows - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            if (matrix[mid][cols - 1] < target) {
                start = mid + 1;
            } else if (matrix[mid][0] > target) {
                end = mid - 1;
            } else {
                start = mid;
                break;
            }
        }

        if (start >= rows) return false;

        int row = start;
        start = 0;
        end = cols - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return false;
    }
};
