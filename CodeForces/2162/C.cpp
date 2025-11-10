#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        if (a == b)
        {
            cout << 0 << endl;
            cout << endl;
            continue;
        }
        int msbA = 31 - __builtin_clz(a);
        int msbB = 31 - __builtin_clz(b);
        if (msbB > msbA)
        {
            cout << -1 << endl;
            continue;
        }

        int target = a ^ b;
        if (target <= a)
        {
            cout << 1 << endl;
            cout << target << endl;
            continue;
        }
        long long temp = (1LL << (msbA + 1)) - 1;
        int x1 = a ^ temp;
        int x2 = temp ^ b;
        cout << 2 << endl;
        cout << x1 << " " << x2 << endl;
    }
    return 0;
}