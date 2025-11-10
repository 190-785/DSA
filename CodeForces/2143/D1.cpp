#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long mod = 1e9 + 7;
        vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0));
        vector<long long> f(n + 2, 0);
        
        for (int v : a) {
            long long newF = 1;
            for (int j = 1; j <= v; ++j) {
                newF = (newF + f[j]) % mod;
            }

            for (int j = v + 1; j <= n; ++j) {
                dp[j][v] = (dp[j][v] + f[j]) % mod;
            }
            
            for (int j = 1; j <= v; ++j) {
                for(int i = j + 1; i <= n; ++i) {
                    dp[i][j] = (dp[i][j] + dp[i][j]) % mod;
                }
            }

            f[v] = (f[v] + newF) % mod;
        }

        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = (ans + f[i]) % mod;
            for (int j = 1; j < i; ++j) {
                ans = (ans + dp[i][j]) % mod;
            }
        }
        
        cout << (ans + 1) % mod << "\n";
    }
    return 0;
}