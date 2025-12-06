class Solution {
public:
    int minimumSumSubarray(std::vector<int>& nums, int l, int r) {
        int n = nums.size();
        int min_sum = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            int current_sum = 0;
            for (int j = i; j < min(i + r, n); ++j) {
                current_sum += nums[j];
                if (j - i + 1 >= l && current_sum > 0) {
                    min_sum = min(min_sum, current_sum);
                }
            }
        }
        
        return (min_sum == INT_MAX) ? -1 : min_sum;
    }
};
