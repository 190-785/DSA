class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = nums.size() - 1;
        int count = 0;
        int i = 0;
        while (i <= j) {
            if (nums[i] == val) {
                if (nums[j] == val) {
                    j--;
                } else {
                    swap(nums[i], nums[j]);
                    i++;
                    j--;
                    count++;
                }
            } else {
                count++;
                i++;
            }
        }
        return count;
    }
};