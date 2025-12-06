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
        if (n % 2 == 1)
        {
            cout << 0 << endl;
            continue;
        }

        int cnt = 0;
        for (int w = 0; w * 4 <= n; w++)
        {
            int rem = n - 4 * w;
            if (rem % 2 == 0)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
