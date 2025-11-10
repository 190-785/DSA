#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long minDiff = LLONG_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            minDiff = min(minDiff, a[i + 1] - a[i]);
        }
        if (minDiff < 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << (minDiff / 2) + 1 << endl;
        }
    }
    return 0;
}