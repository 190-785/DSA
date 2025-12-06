class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int lowIdx =
                lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) -
                nums.begin();
            int highIdx =
                upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) -
                nums.begin();
            res += highIdx - lowIdx;
        }

        return res;
    }
};
