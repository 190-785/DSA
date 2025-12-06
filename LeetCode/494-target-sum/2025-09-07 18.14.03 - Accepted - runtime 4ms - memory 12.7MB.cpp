class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int TSum=accumulate(nums.begin(),nums.end(),0);
        int sum=(TSum-target);
        int n=nums.size();
        if(sum<0 || sum%2!=0) return 0;
        sum/=2;
        vector<int> prev(sum+1,0);
        vector<int> curr(sum+1,0);
        prev[0]=1,curr[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                int notPick=prev[j];
                int pick=0;
                if(nums[i-1]<=j) pick=prev[j-nums[i-1]];
                curr[j]=(pick+notPick);
            }
            prev=curr;
        }
        return prev[sum];
    }
};