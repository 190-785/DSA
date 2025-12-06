class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        if (n < 3)
            return 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n / 3; i++) {
            res += nums[n - 2 - (2 * i)];
        }
        return res;
    }
};