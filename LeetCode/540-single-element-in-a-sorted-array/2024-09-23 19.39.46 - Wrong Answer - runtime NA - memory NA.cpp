class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n == 0)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n] != nums[n - 1])
            return nums[n];

        int start = 1;
        int end = n - 1;
        while (start < end) {
            int mid = (start + end) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }
            if (mid % 2 == 0) {
                // Element is on left half
                if (nums[mid] == nums[mid - 1]) {
                    end = mid - 1;
                }
                // Element is on Right half
                else {
                    start = mid + 1;
                }
            } else {
                // Element is on Right Half
                if (nums[mid] == nums[mid - 1]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};