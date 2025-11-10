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

        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            if (x >= 0 && x <= n)
                ++cnt[x];
        }

        vector<int> f;
        f.reserve(n);
        int maxF = 0;
        for (int v = 1; v <= n; ++v)
        {
            if (cnt[v] > 0)
            {
                f.push_back(cnt[v]);
                if (cnt[v] > maxF)
                    maxF = cnt[v];
            }
        }

        int res = 0;
        for (int k = 1; k <= maxF; ++k)
        {
            int avail = 0;
            for (int c : f)
                if (c >= k)
                    ++avail;
            int cur = avail * k;
            if (cur > res)
                res = cur;
        }

        cout << res << '\n';
    }

    return 0;
}
