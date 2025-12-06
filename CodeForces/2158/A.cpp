#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, y, r;
        cin >> n;
        cin >> y >> r;
        int total = y / 2 + r;
        cout << min(n, total) << endl;
    }
    return 0;
}