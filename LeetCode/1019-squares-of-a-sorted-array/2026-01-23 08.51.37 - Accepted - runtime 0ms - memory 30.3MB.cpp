class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n);
        int left=0,right=n-1;
        int newLeft=0,newRight=n-1;
        while(left<=right){
            if(abs(nums[left])>abs(nums[right])){
                arr[newRight]=pow(nums[left],2);
                newRight--;
                left++;
            }
            else{
                arr[newRight]=pow(nums[right],2);
                newRight--;
                right--;
            }
            // cout<<newRight<<" ";
            // cout<<right<<" "<<left<<" ";
            // cout<<endl;
        }
        //arr[newRight]=pow(nums[right],2);
        return arr;
    }
};