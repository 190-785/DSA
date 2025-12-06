class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for (int i = 0; i < n; i++) {
            vector<int> freq(n, 0);
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] > 0 && matrix[i][j] <= n) {
                    freq[matrix[i][j] - 1]++;
                }
            }
            if (count(freq.begin(), freq.end(), 0) > 0) return false;
        }
        
        for (int j = 0; j < n; j++) {
            vector<int> freq(n, 0);
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] > 0 && matrix[i][j] <= n) {
                    freq[matrix[i][j] - 1]++;
                }
            }
            if (count(freq.begin(), freq.end(), 0) > 0) return false;
        }
        
        return true;
    }
};
