#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int maxVal = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            maxVal = max(maxVal, a[i]);
        }
        int maxFreq = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == maxVal) {
                maxFreq++;
            }
        }
        cout << maxFreq <<endl;
    }
    return 0;
}