#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    for (int i = 0; i < m; i++)
        cin >> c[i];

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        int amt = min(b, c[a]);
        res += amt;
        c[a] -= amt;
    }
    cout << res << endl;

    return 0;
}