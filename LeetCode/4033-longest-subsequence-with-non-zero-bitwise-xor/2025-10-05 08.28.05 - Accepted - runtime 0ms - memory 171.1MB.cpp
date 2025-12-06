class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int n = nums.size();
        int xore = nums[0];
        for (int i = 1; i < n; i++) {
            xore ^= nums[i];
        }
        if (xore != 0)
            return n;
        bool zeroes = true;
        for (int num : nums) {
            if (num != 0) {
                zeroes = false;
                break;
            }
        }
        if (zeroes)
            return 0;
        return n - 1;
    }
};