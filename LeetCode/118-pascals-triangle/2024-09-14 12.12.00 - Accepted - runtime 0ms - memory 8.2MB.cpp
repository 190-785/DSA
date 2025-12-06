class Solution {
public:
    vector<int> generateRow(int row) {
        vector<int> rows;
        rows.push_back(1);
        long long ans = 1;
        for (int i = 1; i <= row; i++) {
            ans = ans * (row - i + 1) / i;
            rows.push_back(ans);
        }
        return rows;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        for (int i = 0; i < numRows; i++) {
            
            triangle.push_back(generateRow(i));
        }
        return triangle;
    }
};
