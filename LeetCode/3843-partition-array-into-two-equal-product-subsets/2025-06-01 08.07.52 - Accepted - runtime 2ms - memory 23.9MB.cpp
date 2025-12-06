class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        __int128 totalProd = 1;
        for (int x : nums)
            totalProd *= x;
        __int128 targetSq = (__int128)target * target;
        if (totalProd != targetSq)
            return false;

        int totalSubsets = 1 << n;
        for (int mask = 1; mask < totalSubsets - 1; mask++) {
            __int128 subsetProd = 1;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subsetProd *= nums[i];
                    if (subsetProd > (__int128)target)
                        break;
                }
            }
            if (subsetProd == target)
                return true;
        }
        return false;
    }
};
