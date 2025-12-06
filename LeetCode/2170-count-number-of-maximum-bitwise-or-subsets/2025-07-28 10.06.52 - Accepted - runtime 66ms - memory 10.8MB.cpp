class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        int count = 0;
        int n = nums.size();
        for (int num : nums) {
            maxOr |= num;
        }
        int totalSubsets = 1 << n;
        for (int i = 0; i < totalSubsets; ++i) {
            int currentOr = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    currentOr |= nums[j];
                }
            }
            if (currentOr == maxOr) {
                count++;
            }
        }
        return count;
    }
};
