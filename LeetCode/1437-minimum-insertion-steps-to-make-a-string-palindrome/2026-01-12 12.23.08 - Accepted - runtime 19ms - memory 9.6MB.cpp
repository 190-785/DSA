class Solution {
public:
    int minInsertions(string s) {
        string revS = s;
        reverse(revS.begin(), revS.end());
        int n = s.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == revS[j - 1]) {
                    curr[j] = prev[j - 1] + 1;
                } else {
                    curr[j] = max(curr[j - 1], prev[j]);
                }
            }
            prev = curr;
        }
        return n - curr[n];
    }
};