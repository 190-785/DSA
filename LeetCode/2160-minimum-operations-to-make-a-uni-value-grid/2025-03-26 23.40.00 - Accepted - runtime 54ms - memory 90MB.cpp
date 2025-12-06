class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for (const auto& row : grid) {
            for (int val : row) {
                nums.push_back(val);
            }
        }
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        int operations = 0;
        for (int num : nums) {
            if (abs(num - median) % x != 0)
                return -1;
            operations += abs(num - median) / x;
        }
        return operations;
    }
};
