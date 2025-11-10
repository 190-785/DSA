#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, n;
        cin >> a >> b >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        long long maxTime = b;
        for (int i = 0; i < n; i++)
            maxTime += min(arr[i], a - 1);

        cout << maxTime << endl;
    }
    return 0;
}
