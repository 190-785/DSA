class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int row = matrix.size();
        int column = matrix[0].size();
        int low = 0;
        int high = row * column - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int mid_value = matrix[mid / column][mid % column];

            if (mid_value == target) {
                return true;
            } else if (mid_value < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};
