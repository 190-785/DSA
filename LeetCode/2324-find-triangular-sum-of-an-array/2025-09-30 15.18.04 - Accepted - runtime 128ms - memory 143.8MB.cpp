class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            vector<int> newNums(n - i - 1);
            for (int j = 0; j < n - i - 1; j++) {
                newNums[j] = (nums[j] + nums[j + 1]) % 10;
            }
            nums = newNums;
        }
        return nums[0];
    }
};