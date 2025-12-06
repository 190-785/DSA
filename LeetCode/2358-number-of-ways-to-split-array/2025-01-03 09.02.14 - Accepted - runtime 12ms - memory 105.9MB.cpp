class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        if(nums.size()<2) return 0;
        vector<long long> prefixSum;
        prefixSum.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            long long back=prefixSum.back();
            prefixSum.push_back(back+nums[i]);
        }
        int res=0;
        for(int i=0;i<nums.size()-1;i++){
            long long temp=prefixSum[i];
            if(prefixSum.back()-temp<=temp){
                res++;
            }
        }
        return res;
    }
};