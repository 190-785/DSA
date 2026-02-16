class Solution {
public:
    int change(int amount, vector<int>& coins) {
        unsigned long long t = amount;
        unsigned long long n = coins.size();
        vector<unsigned long long> prev(t + 1, 0);
        for (unsigned long long i = 0; i <= t; i++)
            prev[i] = (i % coins[0] == 0);
        for (unsigned long long i = 1; i < n; i++) {
            vector<unsigned long long> curr(t + 1, 0);
            for (unsigned long long j = 0; j <= t; j++) {
                unsigned long long notTake = prev[j];
                unsigned long long take = 0;
                if (coins[i] <= j)
                    take = curr[j - coins[i]];
                curr[j] = take + notTake;
            }
            prev = curr;
        }
        return static_cast<int>(prev[t]);
    }
};