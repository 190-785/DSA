class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i,j=0;
        int n=nums.size();
        for(i=0;i<n;i++){
            if(nums[i]==0){
                for(j=i+1;j<n;j++){
                    nums[j-1]=nums[j];
                }
                nums[j-1]=0;
            }
        }
    }
};