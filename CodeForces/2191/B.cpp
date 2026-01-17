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
        vector<int> a(n);
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] <= n)
                cnt[a[i]]++;
        }

        int mex = 0;
        while (mex <= n && cnt[mex] > 0)
            mex++;

        if (mex == 0)
        {
            cout << "NO" << endl;
        }
        else if (mex == 1)
        {
            if (cnt[0] == 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
