class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int i;
        sort(nums.begin(),nums.begin()+n);
        for(i=0;i<n;i++){
            if(nums[i]!=i){
                return i;
            }
        }
        return i;
    }
};