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
        if (n < 4 || n % 2 == 1)
            cout << -1 << '\n';
        else
        {
            long long minBus = (n + 5) / 6;
            long long maxBus = n / 4;
            cout << minBus << " " << maxBus << '\n';
        }
    }

    return 0;
}