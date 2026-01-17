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

        vector<int> a(n), b;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        b = a;
        sort(b.begin(), b.end());

        int diff = -1;
        bool isPossible = true;

        for (int i = 0; i < n; i++)
        {
            int sortedPos = -1;

            for (int j = 0; j < n; j++)
            {
                if (b[j] == a[i])
                {
                    sortedPos = j;
                    break;
                }
            }

            int curDiff = (i % 2) ^ (sortedPos % 2);

            if (diff == -1)
            {
                diff = curDiff;
            }
            else if (curDiff != diff)
            {
                isPossible = false;
                break;
            }
        }

        cout << (isPossible ? "YES" : "NO");
        cout << endl;
    }
}
