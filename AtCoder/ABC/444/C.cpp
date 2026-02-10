#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n < 2)
    {
        cout << a[0] << endl;
        return 0;
    }

    sort(a.begin(), a.end());

    if (n % 2 != 0)
    {
        cout << a[n - 1] << endl;
        return 0;
    }

    int maxL = a[n - 1];
    auto it = lower_bound(a.begin(), a.end(), maxL);
    int idx = it - a.begin();

    bool possible = true;
    if (idx % 2 != 0)
    {
        possible = false;
    }
    else
    {
        for (int i = 0; i < idx / 2; i++)
        {
            if (a[i] + a[idx - 1 - i] != maxL)
            {
                possible = false;
                break;
            }
        }
    }
    int L = a[0] + a[n - 1];
    bool isUnbroken = true;
    for (int i = 0; i < n / 2; i++)
    {
        if ((a[i] + a[n - 1 - i]) != L)
        {
            isUnbroken = false;
            break;
        }
    }
    if (possible)
        cout << maxL<<" ";
    if (isUnbroken)
        cout << L;
    cout << endl;

    return 0;
}
