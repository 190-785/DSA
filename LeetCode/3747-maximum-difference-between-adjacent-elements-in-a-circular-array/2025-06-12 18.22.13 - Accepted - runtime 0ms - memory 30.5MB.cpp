class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int temp = abs(nums[i] - nums[i + 1]);
            if (temp > res)
                res = temp;
        }
        int temp = abs(nums[n - 1] - nums[0]);
        return temp > res ? temp : res;
    }
};