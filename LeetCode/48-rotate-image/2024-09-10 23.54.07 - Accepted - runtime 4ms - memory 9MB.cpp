class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i,j;
        int n=size(matrix);
        int m=size(matrix[0]);
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(i<j){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
        for(i=0;i<n;i++){
           reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};