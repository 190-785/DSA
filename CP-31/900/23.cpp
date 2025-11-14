#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
            cin >> a[i];

        long long totalAnd = a[0];
        for (long long i = 1; i < n; i++)
            totalAnd &= a[i];

        cout << totalAnd << endl;
    }
    return 0;
}
