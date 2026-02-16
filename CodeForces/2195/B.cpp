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

        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            int val = arr[i];

            while (j % 2 == 0)
                j /= 2;

            while (val % 2 == 0)
                val /= 2;

            if (j != val)
            {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
