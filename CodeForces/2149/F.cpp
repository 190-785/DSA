#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long h, d;
        cin >> h >> d;
        long long cur = h, moves = 0, turns = 0;
        long long rem = d;
        while (rem > 0)
        {
            long long k = (long long)((-1.0 + sqrt(8.0 * cur - 7)) / 2);
            k = min(k, rem);
            if (k == 0)
            {
                cur++;
                turns++;
                continue;
            }
            moves += k;
            turns += k;
            cur -= k * (k + 1) / 2;
            rem -= k;
            if (rem > 0)
            {
                cur++;
                turns++;
            }
        }
        cout << turns << "\n";
    }
}
