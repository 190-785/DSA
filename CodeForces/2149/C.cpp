#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> freq(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (a <= n)
                ++freq[a];
        }
        int missing = 0;
        for (int i = 0; i < k; ++i)
        {
            if (freq[i] == 0)
                ++missing;
        }
        int extraK = freq[k];
        int res = max(missing, extraK);
        cout << res << '\n';
    }
    return 0;
}