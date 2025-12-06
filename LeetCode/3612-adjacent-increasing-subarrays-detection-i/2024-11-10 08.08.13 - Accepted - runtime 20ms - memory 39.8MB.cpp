class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k) return false;

        for (int i = 0; i <= n - 2 * k; ++i) {
            bool first_increasing = true;
            bool second_increasing = true;

            for (int j = 0; j < k - 1; ++j) {
                if (nums[i + j] >= nums[i + j + 1]) {
                    first_increasing = false;
                    break;
                }
            }

            if (!first_increasing) continue;

            for (int j = 0; j < k - 1; ++j) {
                if (nums[i + k + j] >= nums[i + k + j + 1]) {
                    second_increasing = false;
                    break;
                }
            }

            if (first_increasing && second_increasing) return true;
        }

        return false;
    }
};
