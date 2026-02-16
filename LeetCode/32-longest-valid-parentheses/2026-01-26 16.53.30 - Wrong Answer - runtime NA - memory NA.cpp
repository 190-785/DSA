class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n < 2)
            return 0;
        stack<char> stk;
        vector<vector<int>> dp;
        stk.push(s[0]);
        int lastNotTaken = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == '(') {
                stk.push(s[i]);
                lastNotTaken = i;
                continue;
            }
            if (!stk.empty()) {
                char prev = stk.top();
                if (prev == '(') {
                    dp.push_back({i, lastNotTaken});
                    lastNotTaken--;
                    stk.pop();
                } else {
                    while (!stk.empty())
                        stk.pop();
                    lastNotTaken = i;
                }
            }
        }
        int res = 0;
        int curr = 1;
        int m = dp.size();
        if (m == 0)
            return 0;
        // cout<<dp.size();
        for (int i = 0; i < m-1; i++) {
            if (dp[i][0] == dp[i + 1][1] - 1) {
                curr++;
            } else {
                res = max(res, curr);
                curr = 1;
            }
            // cout << dp[i][0] << " " << dp[i][1] << endl;
        }
        // cout<<dp.size();

        res = max(res, curr);
        return res * 2;
    }
};