class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;
        for (int i = nums.size() - 2; i >= 0; --i) {
            while (nums[i] > nums[i + 1]) {
                int divisor = -1;
                for (int j = nums[i] / 2; j > 1; --j) {
                    if (nums[i] % j == 0) {
                        divisor = j;
                        break;
                    }
                }
                if (divisor == -1 || divisor == nums[i]) {
                    return -1;
                }
                nums[i] = divisor;
                operations++;
            }
        }
        return operations;
    }
};
