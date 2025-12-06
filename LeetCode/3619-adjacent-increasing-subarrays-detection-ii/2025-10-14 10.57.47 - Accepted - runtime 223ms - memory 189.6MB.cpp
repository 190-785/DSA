class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        // LIS = Longest Increasing Subsequence
        // LDS = Longest Decreasing Subsequence
        vector<int> LIS(n, 1), LDS(n, 1);
        // Building LIS from Left to Right
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                LIS[i] += LIS[i - 1];
        }
        // Technically building LIS but from right to left
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1])
                LDS[i] += LDS[i + 1];
        }
        int res = 1;
        // Check the max Value of K present in both LIS and LDS which are
        // consecutive
        for (int i = 0; i < n - 1; i++) {
            res = max(res, min(LIS[i], LDS[i + 1]));
        }
        return res;
    }
};