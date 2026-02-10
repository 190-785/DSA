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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        long long res = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1] + 1)
            {
                res += arr[i] - (arr[i - 1] + 1);
                arr[i] = arr[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] > arr[i + 1] + 1)
            {
                res += arr[i] - (arr[i + 1] + 1);
                arr[i] = arr[i + 1] + 1;
            }
        }
        cout << res << endl;
    }
    return 0;
}
