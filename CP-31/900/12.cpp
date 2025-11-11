#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {   int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long res = a[n-1] - a[0];
        for (int i = 1; i < n; i++)
            res = max(res, a[i] - a[0]);

        for (int i = 0; i < n - 1; i++)
            res = max(res, a[n - 1] - a[i]);

        for (int i = 0; i < n - 1; i++)
            res = max(res, a[i] - a[i + 1]);
        cout << res << endl;
    }
    return 0;
}