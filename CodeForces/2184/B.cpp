#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long s, k, m;
        cin >> s >> k >> m;
        long long fullInt = m / k;
        long long remTime = m % k;
        if (s <= k)
        {
            cout << max(0LL, s - remTime) << endl;
        }
        else
        {
            if (fullInt % 2 == 0)
                cout << s - remTime << endl;
            else
                cout << k - remTime << endl;
        }
    }

    return 0;
}