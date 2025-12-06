class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
         int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        while (mid >= left && mid <= right) {
            if (target < nums[mid]) {
                right = mid - 1;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                return mid;
            }
            mid = (left + right) / 2;
        }
        return mid+1;
    }
};