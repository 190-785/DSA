class Solution {
public:
    int robcheck(span<int> nums) {
        int n = nums.size();
        int prev = 0, prev2 = 0;
        for (int i = 0; i < n; i++) {
            int take = nums[i];
            if (i > 1)
                take += prev2;
            int curr = max(take, prev);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0]; 

        return max(
            robcheck(span<int>(nums).subspan(1)), // Exclude first house
            robcheck(span<int>(nums).subspan(0, nums.size() - 1)) // Exclude last house
        );
    }
};
