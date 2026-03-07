#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<pair<long long, int>> sortedArr;
    for (int i = 0; i < n; i++)
        sortedArr.push_back({arr[i], i});

    sort(sortedArr.begin(), sortedArr.end());
    while (q--)
    {
        int k;
        cin >> k;
        set<int> remv;
        for (int i = 0; i < k; i++)
        {
            int b;
            cin >> b;
            remv.insert(b - 1);
        }

        for (int i = 0; i < n; i++)
        {
            if (remv.find(sortedArr[i].second) == remv.end())
            {
                cout << sortedArr[i].first << endl;
                break;
            }
        }
    }
    return 0;
}