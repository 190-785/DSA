class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxAnd = nums[0];
        int maxLen = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == maxAnd) {
                maxLen++;
            } else if (nums[i] > maxAnd) {
                maxAnd = nums[i];
                maxLen = 1;
            }
        }
        return maxLen;
    }
};