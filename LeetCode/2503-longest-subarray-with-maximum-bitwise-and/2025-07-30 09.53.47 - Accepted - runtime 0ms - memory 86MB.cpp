class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxAnd = nums[0];
        int maxLen = 1;
        int len = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == maxAnd) {
                len++;
                maxLen = max(maxLen, len);
            } else if (nums[i] > maxAnd) {
                len = 1;
                maxAnd = nums[i];
                maxLen = 1;
            } else {
                len = 0;
            }
        }
        return maxLen;
    }
};