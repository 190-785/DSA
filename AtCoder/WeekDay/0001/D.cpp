#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<long long> A(N + 1), B(N + 1);
    for (int i = 1; i <= N; i++) 
        cin >> A[i] >> B[i];

    vector<vector<long long>> dp(N + 1, vector<long long>(M + 1, -1));
    dp[0][0] = 0; 
    long long res = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = -1;
        }
        
        for (int j = 0; j <= M; j++) {
            if (dp[i - 1][j] != -1) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
        
        for (int p = max(0, i - K); p < i; p++) {
            for (int j = B[i]; j <= M; j++) {
                if (dp[p][j - B[i]] != -1) {
                    dp[i][j] = max(dp[i][j], dp[p][j - B[i]] + A[i]);
                }
            }
        }
        
        for (int j = 0; j <= M; j++) {
            if (dp[i][j] != -1) {
                res = max(res, dp[i][j]);
            }
        }
    }
    cout << res << endl;    
    return 0;
}
