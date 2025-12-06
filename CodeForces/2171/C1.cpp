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
        vector<int> a(n), b(n);
        int xa = 0, xb = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            xa ^= a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            xb ^= b[i];
        }
        if (xa == xb)
        {
            cout << "Tie" << endl;
            continue;
        }
        int last = -1;
        for (int i = n - 1; i >= 0; i--)
            if (a[i] != b[i])
            {
                last = i;
                break;
            }
        if ((last + 1) % 2 == 1)
            cout << "Ajisai" << endl;
        else
            cout << "Mai" << endl;
    }
    return 0;
}
