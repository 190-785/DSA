#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; ++i)
            cin >> a[i];
        long long totalNumberOfTwos = 0;
        long long currentNumberOfTwos = 0;
        for (long long i = 0; i < n; ++i)
            if (a[i] == 2)
                ++totalNumberOfTwos;
        long long res = -1;
        for (long long i = 0; i < n; ++i) {
            if (a[i] == 2)
                ++currentNumberOfTwos;
            if (currentNumberOfTwos == totalNumberOfTwos - currentNumberOfTwos) {
                res = i + 1;
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}
