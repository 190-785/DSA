class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        int n = power.size();
        int i = 0, j = 0;
        vector<long long> dp(n, 0);
        while (i < n) {
            int prevIdx = i - 1;
            long long curr = power[i];
            long long freq = 0;
            while (i < n && power[i] == curr) {
                freq++;
                i++;
            }
            while (j < n && power[j] < curr - 2) {
                j++;
            }
            long long pick = curr * freq + ((j - 1 >= 0) ? dp[j - 1] : 0);
            long long notPick = ((prevIdx >= 0) ? dp[prevIdx] : 0);
            dp[i - 1] = max(pick, notPick);
        }
        return dp[n - 1];
    }
};