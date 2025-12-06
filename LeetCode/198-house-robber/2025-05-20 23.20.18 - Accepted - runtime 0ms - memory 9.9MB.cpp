class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = 0, prev2 = 0;
        for (int i = 0; i < n; i++) {
            int take = nums[i];
            if (i > 1)
                take += prev2;
            // nottake=prev;
            int curr = max(take, prev);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};