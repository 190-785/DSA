#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, p;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> p;
        p--;
        int x = arr[p];

        vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            b[i] = arr[i] ^ x;
        }
        int left = 0;
        if (b[0] == 1)
            left++;
        for (int i = 1; i <= p; i++)
        {
            if (b[i] != b[i - 1])
                left++;
        }
        int right = 0;
        if (b[n - 1] == 1)
            right++;
        for (int i = n - 2; i >= p; i--)
        {
            if (b[i] != b[i + 1])
                right++;
        }
        cout << max(left, right) << endl;
    }
    return 0;
}