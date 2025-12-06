class Solution {
public:
    int findMin(vector<int>& nums) {
        int minNum = INT_MAX;
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            minNum = min(nums[mid],minNum);
            // Min on left side
            if (nums[start] <= nums[mid] && nums[start] <= nums[end]) {
                end = mid - 1;
            } // Min on Right Side
            else if (nums[start] <= nums[mid] && nums[start] >= nums[end]) {
                start = mid + 1;
            } // Min on left side
            else if (nums[start] >= nums[mid] && nums[start] >= nums[end]) {
                start = mid + 1;
            } // Min on Right Side
            else {
                end = mid - 1;
            }
        }
        return minNum;
    }
};