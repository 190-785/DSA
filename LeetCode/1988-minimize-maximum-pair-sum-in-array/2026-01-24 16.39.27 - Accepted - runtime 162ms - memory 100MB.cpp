class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res=0;
        int n=nums.size();
        for(int i=0;i<n/2;i++){
            int curr=nums[i]+nums[n-i-1];
            res=max(res,curr);
        }
        return res;
    }
};