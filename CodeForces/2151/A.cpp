#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; i++)
            cin >> a[i];
        bool multiple = false;
        for (int i = 1; i < m; i++)
        {
            if (a[i] == 1 && a[i - 1] != a[i - 1] + 1)
            {
                multiple = true;
                break;
            }
            if (a[i] != a[i - 1] + 1 && !(a[i] == 1 && a[i - 1] > 1))
            {
                multiple = true;
                break;
            }
        }
        if (multiple)
        {
            cout << 1 << "\n";
        }
        else
        {
            int kMin = *max_element(a.begin(), a.end());
            cout << max(0, n - kMin + 1) << "\n";
        }
    }
}
