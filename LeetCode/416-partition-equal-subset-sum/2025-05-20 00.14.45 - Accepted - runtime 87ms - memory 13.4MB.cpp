class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;
        int targetSum = sum / 2;
        vector<bool> dp(targetSum + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            for (int j = targetSum; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[targetSum];
    }
};
