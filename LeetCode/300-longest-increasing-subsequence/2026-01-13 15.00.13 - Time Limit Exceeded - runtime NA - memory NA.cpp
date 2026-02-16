class Solution {
public:
    int func(vector<int>& nums, int idx, int prev, int n) {
        if (idx == n)
            return 0;
        int notTake = func(nums, idx + 1, prev, n);
        int take;
        if (prev == -1 || nums[prev] < nums[idx]) {
            take = func(nums, idx + 1, idx, n) + 1;
        } else {
            take = func(nums, idx + 1, prev, n);
        }
        return max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        return func(nums, 0, -1, nums.size());
    }
};