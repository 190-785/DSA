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
        pair<pair<int, int>, int> last = {{-1, -1}, -1};
        for (int i = 0; i < m - 1; i++) {
            cout << "dp " << dp[i][0] << " " << dp[i][1] << endl;
            if ((dp[i][0] == (dp[i + 1][1] - 1)) ||
                (dp[i][0] == (dp[i + 1][0] - 1))) {
                curr++;
                if (last.second != -1) {
                    if (dp[i][1] == last.first.first + 1 ||
                        dp[i][1] == last.first.second + 1) {
                        curr += last.second;
                    }
                }
                cout << "Curr " << curr << endl;
            } else {
                cout << last.first.first << " " << last.first.second << " "
                     << last.first.second << endl;
                
                cout << "Curr " << curr << endl;
                res = max(res, curr);
                last = {{dp[i][0], dp[i][1]}, curr};
                curr = 1;
            }
        }
                    cout << "dp " << dp[m-1][0] << " " << dp[m-1][1] << endl;

        // cout<<dp.size();
        cout<<"res "<<res;
        if (m >= 2 && (last.second != -1 || last.first.first == dp[m - 2][0])) {
            if (dp[m - 1][1] == last.first.first + 1 ||
                dp[m - 1][1] == last.first.second + 1) {
                curr += last.second;
            }
        }
        res = max(res, curr);
        return res * 2;
    }
};