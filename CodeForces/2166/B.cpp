#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, n;
        cin >> a >> b >> n;
        if (a == b || (long long)n * b <= a)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    return 0;
}