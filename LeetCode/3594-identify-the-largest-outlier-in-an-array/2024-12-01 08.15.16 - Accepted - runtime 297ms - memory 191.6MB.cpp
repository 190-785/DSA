class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        int largestOutlier = INT_MIN;
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        for (int sumCandidate : nums) {
            long long outlierCandidate = totalSum - 2LL * sumCandidate;
            if (outlierCandidate >= INT_MIN && outlierCandidate <= INT_MAX &&
                freq[outlierCandidate] > 0) {
                if (outlierCandidate == sumCandidate &&
                    freq[sumCandidate] < 2) {
                    continue;
                }
                largestOutlier =
                    max(largestOutlier, static_cast<int>(outlierCandidate));
            }
        }

        return largestOutlier;
    }
};
