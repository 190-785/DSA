class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        if (n <= k && m <= k)
            return 0;

        long long cost = LLONG_MAX;
        if (n > k) {
            for (int len1 = 1; len1 < n; ++len1) {
                int len2 = n - len1;
                if (len1 <= k && len2 <= k) {
                    cost = min(cost, (long long)len1 * len2);
                }
            }
        }
        if (m > k) {
            for (int len1 = 1; len1 < m; ++len1) {
                int len2 = m - len1;
                if (len1 <= k && len2 <= k) {
                    cost = min(cost, (long long)len1 * len2);
                }
            }
        }

        return cost == LLONG_MAX ? 0 : cost;
    }
};
