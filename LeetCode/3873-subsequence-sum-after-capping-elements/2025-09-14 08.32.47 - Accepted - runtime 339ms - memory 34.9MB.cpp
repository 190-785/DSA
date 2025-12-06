class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> answer(n, false);
        vector<int> count(n + 1, 0);
        for (int num : nums) {
            count[num]++;
        }
        vector<int> suffix(n + 2, 0);
        for (int i = n; i >= 1; i--) {
            suffix[i] = suffix[i + 1] + count[i];
        }
        vector<bool> dp(k + 1, false);
        dp[0] = true;
        for (int x = 1; x <= n; x++) {
            int num = suffix[x];
            for (int s = 0; s <= k; s++) {
                if (dp[s]) {
                    long long gap = k - s;
                    if (gap >= 0 && gap % x == 0) {
                        if (gap / x <= num) {
                            answer[x - 1] = true;
                            break;
                        }
                    }
                }
            }
            int numX = count[x];
            if (numX > 0) {
                for (int i = 0; i < numX; i++) {
                    for (int s = k; s >= x; s--) {
                        dp[s] = dp[s] || dp[s - x];
                    }
                }
            }
        }
        return answer;
    }
};