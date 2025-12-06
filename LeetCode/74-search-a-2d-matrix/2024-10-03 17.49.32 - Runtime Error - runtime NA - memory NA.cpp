class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col=matrix[0].size();
        int row=matrix.size();
        int start=0;
        int end=row;
        while(start<=end){
            int mid=(start+end)/2;
            if(matrix[mid][col-1]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        int startRow=start;
        start=0;
        end=col;
        while(start<=end){
            int mid=(start+end)/2;
            if(matrix[startRow][mid]>target){
                end=mid-1;
            }
            else if(matrix[startRow][mid]==target){
                return true;
            }
            else{
                start=mid+1;
            }
        }
        return false;
    }
};