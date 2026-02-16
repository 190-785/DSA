class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        
        int rows = matrix.size();
        int columns = matrix[0].size();

        for (int i = 0; i < rows; i++) {
            if (target >= matrix[i][0] && target <= matrix[i][columns - 1]) {
                int low = 0;
                int high = columns - 1;
                
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (matrix[i][mid] == target) {
                        return true;
                    } else if (matrix[i][mid] < target) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
        }
        return false;
    }
};