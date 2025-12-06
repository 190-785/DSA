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
        vector<vector<long long>> a(n, vector<long long>(n));
        int di[4] = {-1, 1, 0, 0};
        int dj[4] = {0, 0, -1, 1};
        long long curr = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = curr++;
            }
        }
        long long res = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                long long cost = a[i][j];
                for (int k = 0; k < 4; k++)
                {
                    int mi = i + di[k];
                    int mj = j + dj[k];
                    if (mi >= 0 && mi < n && mj >= 0 && mj < n)
                    {
                        cost += a[mi][mj];
                    }
                }
                res = max(res, cost);
            }
        }
        cout << res << endl;
    }

    return 0;
}
