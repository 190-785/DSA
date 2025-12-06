class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        long long odd1 = 0, odd2 = 0, even1 = 0, even2 = 0;
        long long total = 0;
        const int MOD = 1e9 + 7;
        for (int num : nums) {
            if (num % 2 != 0) {
                long long append = (total - odd2 + MOD) % MOD;
                long long newSub = (1 + append) % MOD;
                total = (total + newSub) % MOD;
                long long newOdd1 = (even1 + even2 + 1) % MOD;
                long long newOdd2 = odd1;
                odd1 = newOdd1;
                odd2 = newOdd2;
            } else {
                long long append = (total - even2 + MOD) % MOD;
                long long newSub = (1 + append) % MOD;
                total = (total + newSub) % MOD;
                long long newEven1 = (odd1 + odd2 + 1) % MOD;
                long long newEven2 = even1;
                even1 = newEven1;
                even2 = newEven2;
            }
        }
        return static_cast<int>(total);
    }
};