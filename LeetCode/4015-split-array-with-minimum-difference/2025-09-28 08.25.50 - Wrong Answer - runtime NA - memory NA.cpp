class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        vector<bool> isInc(n);
        isInc[0] = true;
        for (int i = 1; i < n; i++) {
            isInc[i] = isInc[i - 1] && (nums[i] > nums[i - 1]);
        }
        vector<bool> isDec(n);
        isDec[n - 1] = true;
        for (int i = n - 2; i >= 0; i--) {
            isDec[i] = isDec[i + 1] && (nums[i] > nums[i + 1]);
        }
        long long minDiff = -1;
        for (int i = 0; i < n; i++) {
            if (isInc[i] && isDec[i]) {
                long long left = prefixSum[i];
                long long right = prefixSum[n - 1] - left;
                long long currDiff = abs(right - left);
                if (minDiff == -1)
                    minDiff = currDiff;
                else
                    minDiff = min(minDiff, currDiff);
            }
        }
        return minDiff;
    }
};