#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        long long h;
        cin >> n >> m >> h;
        vector<long long> a(n + 1);
        for (long long i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<long long> add(n + 1, 0);
        vector<long long> prevVer(n + 1, 0);
        long long currVer = 1;
        for (long long i = 0; i < m; i++) {
            long long b;
            long long c;
            cin >> b >> c;
            if (prevVer[b] != currVer) {
                add[b] = 0;
                prevVer[b] = currVer;
            }
            add[b] += c;
            if (a[b] + add[b] > h) 
                currVer++;
            
        }
        for (long long i = 1; i <= n; i++) {
            long long value = a[i];
            if (prevVer[i] == currVer) {
                value += add[i];
            }
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}
