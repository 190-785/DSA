class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();

        for (int p = 0; p < n - 5; ++p) {
            for (int q = p + 2; q < n - 3; ++q) {
                for (int r = q + 2; r < n - 1; ++r) {
                    for (int s = r + 2; s < n; ++s) {
                        if (nums[p] * nums[r] == nums[q] * nums[s]) {
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }
};
