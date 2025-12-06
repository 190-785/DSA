class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        const int MOD = 1e9 + 7;

        for (int i = 0; i < 31; ++i) {
            if ((n >> i) & 1)
                powers.push_back(1 << i);
        }
        vector<int> res;
        for (auto& q : queries) {
            int left = q[0], right = q[1];
            long long prod = 1;
            for (int i = left; i <= right; ++i) {
                prod = (prod * powers[i]) % MOD;
            }
            res.push_back(prod);
        }

        return res;
    }
};
