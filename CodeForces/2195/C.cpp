#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> prev(7, INT_MAX), curr(7);

        for (int v = 1; v <= 6; v++)
            prev[v] = (a[0] == v ? 0 : 1);

        for (int i = 1; i < n; i++)
        {
            for (int v = 1; v <= 6; v++)
            {
                curr[v] = INT_MAX;
                int cost = (a[i] == v ? 0 : 1);

                for (int u = 1; u <= 6; u++)
                {
                    if (u != v && u + v != 7)
                        curr[v] = min(curr[v], prev[u] + cost);
                }
            }
            prev = curr;
        }

        cout << *min_element(prev.begin() + 1, prev.end()) << endl;
    }
    return 0;
}
