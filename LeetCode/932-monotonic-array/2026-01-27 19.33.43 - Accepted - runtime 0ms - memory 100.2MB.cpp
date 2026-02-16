class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return true;
        bool isIncreasing = true, isDecreasing = true;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1])
                isDecreasing = false;
            if (nums[i] > nums[i + 1])
                isIncreasing = false;
            if (!isDecreasing && !isIncreasing)
                break;
        }
        return isDecreasing || isIncreasing;
    }
};