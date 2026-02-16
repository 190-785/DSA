class Solution {
public:
    bool rec(string s, string p, int i, int j,vector<vector<int>>& dp) {
        if (i < 0 && j < 0)
            return true;
        if (j < 0 && i >= 0)
            return false;
        if (i < 0 && j >= 0) {
            while (j >= 0) {
                if (p[j] != '*')
                    return false;
                j--;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j]=rec(s, p, i - 1, j - 1,dp);

        if (p[j] == '*') {
            return dp[i][j]=rec(s, p, i - 1, j,dp) || rec(s, p, i, j - 1,dp);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(s, p, n - 1, m - 1,dp);
    }
};