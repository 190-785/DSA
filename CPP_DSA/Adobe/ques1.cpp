#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> speeds(n);
    for (int i = 0; i < n; i++) {
        cin >> speeds[i];
    }
    
    vector<long long> dp(1 << n, LLONG_MAX);
    dp[0] = 0;
    
    for (int mask = 0; mask < (1 << n); mask++) {
        if (dp[mask] == LLONG_MAX) continue;
        
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue;
            
            int new_mask = mask | (1 << i);
            
            int min_speed = speeds[i], max_speed = speeds[i];
            for (int j = 0; j < n; j++) {
                if (new_mask & (1 << j)) {
                    min_speed = min(min_speed, speeds[j]);
                    max_speed = max(max_speed, speeds[j]);
                }
            }
            
            long long new_difficulty = max_speed - min_speed;
            dp[new_mask] = min(dp[new_mask], dp[mask] + new_difficulty);
        }
    }
    
    cout << dp[(1 << n) - 1] << endl;
    
    return 0;
}