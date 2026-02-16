class Solution {
public:
    static const int MOD = 1000000007;
    long long modInverse(long long base) {
        long long res = 1;
        long long exp = MOD - 2;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    int countAnagrams(string s) {
        int n = s.size();
        vector<long long> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        long long res = 1;
        int i = 0;
        while (i < n) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            vector<int> freq(26, 0);
            int len = 0;
            while (i < n && s[i] != ' ') {
                freq[s[i] - 'a']++;
                len++;
                i++;
            }
            long long ways = fact[len];
            for (int f : freq) {
                if (f > 1) {
                    ways = (ways * modInverse(fact[f])) % MOD;
                }
            }
            res = (res * ways) % MOD;
        }
        return res;
    }
};
