class Solution {
public:
    bool check(vector<int>& nums) {
        int check=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                check++;
                break;
            }
        }
        if(check==1 && nums[0]<nums[n-1]){
            return false;
        }
        return true;
    }
};