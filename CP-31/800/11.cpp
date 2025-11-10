#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            res = 0;
            break;
        }
        res = min(res, abs(a[i]));
    }
    cout << res << endl;

    return 0;
}
