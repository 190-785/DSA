#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
            cin >> a[i];

        map<long long, long long> freq;
        for (long long i = 0; i < n; i++)
            freq[a[i]]++;

        long long maxFreq = 0;
        for (auto i : freq)
            maxFreq = max(maxFreq, i.second);

        long long ops = 0;
        while (maxFreq < n)
        {
            ops++;
            if (maxFreq * 2 <= n)
            {
                ops += maxFreq;
                maxFreq *= 2;
            }
            else
            {
                ops += n - maxFreq;
                maxFreq = n;
            }
        }

        cout << ops << endl;
    }
    return 0;
}
