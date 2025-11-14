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

        sort(a, a + n);
        long long maxNum = a[n - 1];
        long long minNum = a[0];
        if (maxNum == minNum)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << maxNum << " ";
            for (int i = 0; i < n - 1; i++)
                cout << a[i] << " ";
            cout << endl;
        }
    }
    return 0;
}
