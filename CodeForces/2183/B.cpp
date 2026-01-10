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

        vector<int> arr(n);
        set<int> present;
        
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            present.insert(arr[i]);
        }

        int mex = 0;
        while (present.count(mex))
            mex++;

        cout << min(mex, k - 1) << endl;
    }

    return 0;
}