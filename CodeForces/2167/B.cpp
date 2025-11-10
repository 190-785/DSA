#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        cout << (s == t ? "YES\n" : "NO\n");
    }
    return 0;
}