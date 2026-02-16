class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        const long long NEG_INF = -1000000000000000000LL;
        vector<vector<long long>> prev(k + 1, vector<long long>(3, NEG_INF));
        vector<vector<long long>> curr(k + 1, vector<long long>(3, NEG_INF));
        prev[0][0] = 0;
        prev[0][1] = -prices[0];
        prev[0][2] = prices[0];
        for (int i = 1; i <= k; i++) {
            prev[i][0] = prev[i][1] = prev[i][2] = NEG_INF;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                long long noAction = prev[j][0];
                long long closeLong =
                    (j >= 1 ? prev[j - 1][1] + prices[i] : NEG_INF);
                long long closeShort =
                    (j >= 1 ? prev[j - 1][2] - prices[i] : NEG_INF);
                curr[j][0] = max({noAction, closeLong, closeShort});
                long long holdLong = prev[j][1];
                long long startLong = prev[j][0] - prices[i];
                curr[j][1] = max(holdLong, startLong);

                long long holdShort = prev[j][2];
                long long startShort = prev[j][0] + prices[i];
                curr[j][2] = max(holdShort, startShort);
            }
            prev.swap(curr);
        }
        long long res = 0;
        for (int i = 0; i <= k; i++) {
            res = max(res, prev[i][0]);
        }
        return res;
    }
};