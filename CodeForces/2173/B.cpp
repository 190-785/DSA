#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        long long minDiff = 0;
        long long maxDiff = 0;

        for (int i = 0; i < n; i++)
        {
            long long nextMin = min(minDiff - a[i], b[i] - maxDiff);
            long long nextMax = max(maxDiff - a[i], b[i] - minDiff);

            minDiff = nextMin;
            maxDiff = nextMax;
        }

        cout << maxDiff << endl;
    }
    return 0;
}
