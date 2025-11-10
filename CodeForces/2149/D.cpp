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
        string s;
        cin >> s;
        vector<long long> aIdx;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                aIdx.push_back(i);
            }
        }

        long long costA = 0;
        if (aIdx.size() > 1)
        {
            long long k = aIdx.size();
            long long median = aIdx[k / 2];
            for (int i = 0; i < k; ++i)
            {
                costA += abs(aIdx[i] - (median - (k / 2) + i));
            }
        }

        vector<long long> bIdx;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'b')
            {
                bIdx.push_back(i);
            }
        }

        long long costB = 0;
        if (bIdx.size() > 1)
        {
            long long k = bIdx.size();
            long long median = bIdx[k / 2];
            for (int i = 0; i < k; i++)
            {
                costB += abs(bIdx[i] - (median - (k / 2) + i));
            }
        }

        cout << min(costA, costB) << endl;
    }
    return 0;
}