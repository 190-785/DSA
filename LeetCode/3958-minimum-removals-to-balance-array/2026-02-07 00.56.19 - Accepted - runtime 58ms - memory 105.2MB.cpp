class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2)
            return 0;
        sort(nums.begin(), nums.end());
        int res = n;
        for (int i = 0; i < n; i++) {
            long long kMinEl = (long long)nums[i] * k;
            auto it = upper_bound(nums.begin() + i, nums.end(), kMinEl);
            int kept = it - (nums.begin() + i);
            res = min(res, n - kept);
        }
        return res;
    }
};