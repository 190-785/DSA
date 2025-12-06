class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        const int MOD = 1e9 + 7;

        for (int i = 0; i < t; i++) {
            vector<long long> nextFreq(26, 0);
            for (int j = 0; j < 25; j++) {
                nextFreq[j + 1] += freq[j];
            }
            nextFreq[0] += freq[25] % MOD;
            nextFreq[1] += freq[25] % MOD;
            freq = nextFreq;
        }

        int64_t res = 0;
        for (int i = 0; i < 26; i++) {
            res = (res + freq[i]) % MOD;
        }
        return static_cast<int>(res);
    }
};
