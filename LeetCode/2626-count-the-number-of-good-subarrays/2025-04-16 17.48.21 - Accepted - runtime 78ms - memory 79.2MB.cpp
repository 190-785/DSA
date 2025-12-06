class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long totalPairs = 0, count = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            totalPairs += freq[nums[right]];
            freq[nums[right]]++;
            while (totalPairs >= k) {
                freq[nums[left]]--;
                totalPairs -= freq[nums[left]];
                left++;
            }
            count += left;
        }

        return count;
    }
};
