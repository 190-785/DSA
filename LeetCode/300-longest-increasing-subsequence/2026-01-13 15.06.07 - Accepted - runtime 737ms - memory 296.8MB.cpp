class Solution {
public:
    int func(vector<int>& nums, vector<vector<int>>& dp, int idx, int prev,
             int n) {
        if (idx == n)
            return 0;
        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];
        int notTake = func(nums, dp, idx + 1, prev, n);
        int take;
        if (prev == -1 || nums[prev] < nums[idx]) {
            take = func(nums, dp, idx + 1, idx, n) + 1;
        } else {
            take = func(nums, dp, idx + 1, prev, n);
        }
        return dp[idx][prev + 1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return func(nums, dp, 0, -1, nums.size());
    }
};