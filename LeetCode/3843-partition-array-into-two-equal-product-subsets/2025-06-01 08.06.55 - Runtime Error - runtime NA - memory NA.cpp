class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        long long totalProd = 1;
        for (int x : nums)
            totalProd *= x;

        if (totalProd % target != 0 || totalProd / target != target)
            return false;

        int totalSubsets = 1 << n;
        for (int mask = 1; mask < totalSubsets - 1; mask++) {
            long long subsetProd = 1;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    subsetProd *= nums[i];
                    if (subsetProd > target)
                        break;
                }
            }
            if (subsetProd == target)
                return true;
        }
        return false;
    }
};
