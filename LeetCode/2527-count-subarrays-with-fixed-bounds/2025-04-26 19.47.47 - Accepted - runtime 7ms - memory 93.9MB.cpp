class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int n = nums.size();
        int leftBound = -1, minIdx = -1, maxIdx = -1;
        for (int right = 0; right < n; right++) {
            if (nums[right] < minK || nums[right] > maxK) {
                leftBound = right;
            }
            if (nums[right] == minK)
                minIdx = right;
            if (nums[right] == maxK)
                maxIdx = right;

            res += max(0, min(minIdx, maxIdx) - leftBound);
        }

        return res;
    }
};
