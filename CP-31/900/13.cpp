#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; ++i) cin >> a[i];

        int countOfZero = 0;
        for (long long value : a) if (value == 0) countOfZero++;

        if (countOfZero == n) {
            cout << 0 << '\n';
            continue;
        }

        bool foundZero = false;
        long long left = 0;
        long long right = n - 1;

        while (left <= right && a[left] == 0) left++;
        while (right >= left && a[right] == 0) right--;

        for (long long i = left; i <= right; ++i) {
            if (a[i] == 0) {
                foundZero = true;
                break;
            }
        }

        cout << (foundZero ? 2 : 1) << '\n';
    }
    return 0;
}
