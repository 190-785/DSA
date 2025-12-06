class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxSum = LLONG_MIN;
        vector<long long> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + static_cast<long long>(nums[i]);
        }

        for (int length = k; length <= n; length += k) {
            for (int i = 0; i + length <= n; ++i) {
                long long sum = prefixSum[i + length] - prefixSum[i];
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};
