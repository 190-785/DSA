class Solution {
public:
    int numSub(string s) {
        int cnt = 0, res = 0, MOD = 1e9 + 7;
        for (char c : s) {
            if (c == '1')
                cnt++;
            else
                cnt = 0;

            res = (res + cnt) % MOD;
        }
        return res;
    }
};