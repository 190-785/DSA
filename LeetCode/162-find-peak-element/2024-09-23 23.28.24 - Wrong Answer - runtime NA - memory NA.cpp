class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n == 0)
            return n;
        if (nums[0] > nums[1])
            return 1;
        if (nums[n] > nums[n - 1])
            return n;

        int start = 1;
        int end = n - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] > nums[mid - 1]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};