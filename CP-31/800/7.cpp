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
        string x, s;
        cin >> x >> s;
        string curr = x;
        bool flag = false;
        int res = -1;
        for (int k = 0; k <= 5; k++)
        {
            if (curr.find(s) != string::npos)
            {
                res = k;
                flag = true;
                break;
            }
            curr += curr;
        }
        cout << res << endl;
    }
    return 0;
}
