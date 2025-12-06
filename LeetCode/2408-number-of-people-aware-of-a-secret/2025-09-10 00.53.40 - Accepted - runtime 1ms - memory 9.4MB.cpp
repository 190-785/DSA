class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<int> people(n + 1, 0);
        people[1] = 1;

        int shareable = 0;
        for (int day = 2; day <= n; ++day) {
            if (day - delay >= 1)
                shareable = (shareable + people[day - delay]) % MOD;
            if (day - forget >= 1)
                shareable = (shareable - people[day - forget] + MOD) % MOD;
            people[day] = shareable;
        }
        int total = 0;
        for (int day = n - forget + 1; day <= n; ++day) {
            total = (total + people[day]) % MOD;
        }

        return total;
    }
};
