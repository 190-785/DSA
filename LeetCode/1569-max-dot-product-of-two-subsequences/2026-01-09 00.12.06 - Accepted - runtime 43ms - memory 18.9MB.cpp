class Solution {
public:
    vector<int> num1, num2;
    vector<vector<int>> memo;
    int n, m;
    const int NEG_INF = -1e9;

    int dp(int i, int j) {
        if (i == n || j == m)
            return NEG_INF;

        if (memo[i][j] != INT_MIN)
            return memo[i][j];

        int take = num1[i] * num2[j];

        int res = max({
            take + dp(i + 1, j + 1), // take both and continue
            take,                    // take and end here
            dp(i + 1, j),            // skip num1[i]
            dp(i, j + 1)             // skip num2[j]
        });

        return memo[i][j] = res;
    }

    int maxDotProduct(vector<int>& a, vector<int>& b) {
        num1 = a;
        num2 = b;
        n = num1.size();
        m = num2.size();

        memo.assign(n, vector<int>(m, INT_MIN));
        return dp(0, 0);
    }
};