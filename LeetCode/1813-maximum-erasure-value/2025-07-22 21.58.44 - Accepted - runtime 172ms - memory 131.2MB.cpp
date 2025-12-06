class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0;
        int currentSum = 0;
        int maxSum = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (seen.find(nums[right]) != seen.end()) {
                currentSum -= nums[left];
                seen.erase(nums[left]);
                left++;
            }
            currentSum += nums[right];
            seen.insert(nums[right]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
