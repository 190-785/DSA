class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curMax = 0, finMax = 0;
        int i, j = 0;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                curMax++;
            } else {
                finMax = max(curMax, finMax);
                curMax = 0;
            }
        }
        finMax = max(curMax, finMax);
        return finMax;
    }
};