class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;

        int rows = matrix.size();
        int columns = matrix[0].size();

        int low = 0;
        int high = rows - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (target >= matrix[mid][0] &&
                target <= matrix[mid][columns - 1]) {
                int rowLow = 0;
                int rowHigh = columns - 1;

                while (rowLow <= rowHigh) {
                    int mid2 = rowLow + (rowHigh - rowLow) / 2;
                    if (matrix[mid][mid2] == target) {
                        return true;
                    } else if (matrix[mid][mid2] < target) {
                        rowLow = mid2 + 1;
                    } else {
                        rowHigh = mid2 - 1;
                    }
                }
                return false;
            } else if (matrix[mid][0] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return false;
    }
};
