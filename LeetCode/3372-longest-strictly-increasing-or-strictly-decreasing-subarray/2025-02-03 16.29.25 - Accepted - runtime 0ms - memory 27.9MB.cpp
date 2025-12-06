class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;
        int maxInc = 1;
        int maxDec = 1;
        int inc = 1;
        int dec = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                dec++;
                inc = 1;
                maxDec = max(maxDec, dec);
            } else if (nums[i] < nums[i + 1]) {
                dec = 1;
                inc++;
                maxInc = max(maxInc, inc);
            } else {
                inc = 1;
                dec = 1;
            }
        }
        return max(maxInc, maxDec);
    }
};