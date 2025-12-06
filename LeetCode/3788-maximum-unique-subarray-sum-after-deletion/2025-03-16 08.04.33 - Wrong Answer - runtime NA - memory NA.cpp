class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen;
        int start = 0, currSum = 0, maxSum = 0;

        for (int end = 0; end < nums.size();end++) {
            while (seen.count(nums[end])) {
                currSum -= nums[start];
                seen.erase(nums[start]);
                ++start;
            }
            currSum += nums[end];
            seen.insert(nums[end]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};
