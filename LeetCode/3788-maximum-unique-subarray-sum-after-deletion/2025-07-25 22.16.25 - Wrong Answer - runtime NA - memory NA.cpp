class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, currentSum = 0, maxSum = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (seen.count(nums[right])) {
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
