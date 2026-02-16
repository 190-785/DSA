class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int t=amount;
        int n=coins.size();
        vector<vector<long long>> dp(n,vector<long long>(t+1,0));
        for(int i=0;i<=t;i++) dp[0][i]=(i%coins[0]==0);
        for(int i=1;i<n;i++){
            for(int j=0;j<=t;j++){
                long long notTake=dp[i-1][j];
                long long take=0;
                if(coins[i]<=j)
                    take=dp[i][j-coins[i]];
                dp[i][j]=take+notTake;
            }
        }
        return static_cast<int>(dp[n-1][t]);
    }
};