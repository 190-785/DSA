class Solution {
public:
    bool recPerma(int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            int n = 0;
            for (int i = 0; i<nums.size(); i++) {
                n = (n * 10) + nums[i];
            }
            if ((n & (n - 1)))
                return false;
            return true;
        }
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            if (nums[0] != 0) {
                if (recPerma(idx + 1, nums)) {
                    return true;
                }
            }
            swap(nums[idx], nums[i]);
        }
        return false;
    }
    bool reorderedPowerOf2(int n) {
        if (!(n & (n - 1)))
            return true;
        vector<int> nums;
        while (n) {
            nums.push_back(n % 10);
            n /= 10;
        }
        return recPerma(0, nums);
    }
};