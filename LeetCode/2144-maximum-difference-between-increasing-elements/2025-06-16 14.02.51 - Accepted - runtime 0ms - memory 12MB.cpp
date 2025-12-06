class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = nums[0];
        int diff = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > mini) {
                diff = max(nums[i] - mini, diff);
            }
            mini = min(nums[i], mini);
        }
        return diff;
    }
};
