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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        n = a.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int mex = 0;
            for (int j = i; j < n; j++)
            {
                long long diff = a[j] - a[i];
                if (diff == mex)
                    mex++;
                else if (diff > mex)
                    break;
            }
            res = max(res, mex);
        }

        cout << res << endl;
    }
    return 0;
}