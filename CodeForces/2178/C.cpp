#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<long long> pref(n + 2, 0);
        for (int i = 2; i <= n; i++) {
            pref[i] = pref[i - 1] + abs(a[i]);
        }

        vector<long long> suff(n + 2, 0);
        for (int i = n; i >= 1; i--) {
            suff[i] = suff[i + 1] + a[i];
        }

        long long maxVal = -2e18; 

        for (int k = 1; k <= n; k++) {
            long long currentVal;
            if (k == 1) {
                currentVal = -suff[2];
            } else {
                currentVal = a[1] + pref[k - 1] - suff[k + 1];
            }
            maxVal = max(maxVal, currentVal);
        }

        cout << maxVal <<endl;
    }
    return 0;
}