class Solution {
public:
    int choices(vector<int>& nums, int start, int end) {
        if (start == end)
            return nums[start];
        int startScore = nums[start] - choices(nums, start + 1, end);
        int endScore = nums[end] - choices(nums, start, end - 1);
        return max(startScore, endScore);
    }
    bool predictTheWinner(vector<int>& nums) {
        /*
            sp1>=sp2
            (sp1-sp2)>=0

        */
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j)
                    dp[i][j] = nums[i];
                else {
                    int pickLeft = nums[i] - dp[i + 1][j];
                    int pickRight = nums[j] - dp[i][j - 1];
                    dp[i][j] = max(pickLeft, pickRight);
                }
            }
        }
        return dp[0][n - 1]>=0;
    }
};