#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int part;
        cin >> part;
        vector<long long> partVal(part);
        for (int i = 0; i < part; i++)
        {
            cin >> partVal[i];
        }

        sort(partVal.begin(), partVal.end());

        long long maxDiff = 0;
        for (int i = 0; i < part; i += 2)
        {
            long long currDiff = partVal[i + 1] - partVal[i];
            if (currDiff > maxDiff)
            {
                maxDiff = currDiff;
            }
        }
        cout << maxDiff << endl;
    }
    return 0;
}