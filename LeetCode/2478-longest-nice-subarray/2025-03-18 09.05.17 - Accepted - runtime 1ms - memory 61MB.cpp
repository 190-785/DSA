class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxL = 1;
        int el = 0;
        int len = 1;
        int i = 1;
        int bit = nums[0];

        while (i < nums.size()) {
            if ((bit & nums[i]) == 0) {
                bit |= nums[i];
                len++;
                maxL = max(maxL, len);
                i++;
            } else {
                bit &= ~nums[el];
                el++;
                len--;
            }
        }

        return maxL;
    }
};
