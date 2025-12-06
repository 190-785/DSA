class Solution {
public:
    int numSub(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int l = 0, r = 0;
        int count = 0;
        int sum = 0, n = nums.size();
        while (r < n) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSub(nums, goal) - numSub(nums, goal - 1);
    }
};