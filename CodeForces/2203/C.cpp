#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long s, m;      
        cin >> s >> m;
        long long lowest = m & -m;
        if (s % lowest != 0)
        {
            cout << -1 << endl;
            continue;
        }

        long long left = 1, right = s / lowest;
        while (left < right)
        {
            long long mid = (left + right) / 2;
            long long rem = s;

            for (int k = 60; k >= 0; k--)
            {
                if ((m >> k) & 1LL)
                {
                    long long val = 1LL << k;
                    long long use = min(mid, rem / val);
                    rem -= use * val;
                    if (rem == 0)
                        break;
                }
            }

            if (rem == 0)
                right = mid;
            else
                left = mid + 1;
        }

        cout << left << endl;
    }

    return 0;
}