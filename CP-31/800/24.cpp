#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long totalXor = 0;
        for (int i = 0; i < n; i++)
            totalXor ^= a[i];

        if (n % 2 == 1)
        {
            cout << totalXor << endl;
        }
        else
        {
            if (totalXor == 0)
                cout << totalXor << endl;
            else
                cout << -1 << endl;
        }
    }
    return 0;
}
