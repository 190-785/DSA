#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, K;
    cin >> n >> K;

    vector<long long> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    long long maxvar = LLONG_MIN;

    for (int i = 0; i <= n - K; i++)
    {
        long long minTemp = h[i];
        long long maxTemp = h[i];

        for (int j = i; j < i + K; j++)
        {
            minTemp = min(minTemp, h[j]);
            maxTemp = max(maxTemp, h[j]);
        }

        long long var = maxTemp - minTemp;
        maxvar = max(maxvar, var);
    }

    cout << maxvar << endl;

    return 0;
}