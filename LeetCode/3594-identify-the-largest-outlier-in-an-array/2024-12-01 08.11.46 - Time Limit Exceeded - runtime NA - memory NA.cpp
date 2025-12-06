class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int largestOutlier = INT_MIN;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;

                int sumCandidate = nums[i];
                int outlierCandidate = nums[j];

                if (totalSum - sumCandidate - outlierCandidate == sumCandidate) {
                    largestOutlier = max(largestOutlier, outlierCandidate);
                }
            }
        }

        return largestOutlier;
    }
};
