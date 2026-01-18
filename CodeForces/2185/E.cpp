#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        string instructions;
        cin >> instructions;
        sort(b.begin(), b.end());
        int alive = n;
        vector<int> deadIdx(n, 0);
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (deadIdx[j] == 1)
                    continue;
                if (instructions[i] == 'L')
                    a[j]--;
                else
                    a[j]++;
                if (binary_search(b.begin(), b.end(), a[j]))
                {
                    deadIdx[j] = 1;
                    alive--;
                }
            }
            cout << alive << " ";
        }
        cout << endl;
    }
    return 0;
}