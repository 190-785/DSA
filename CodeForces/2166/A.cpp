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
        string s;
        cin >> s;

        char target = s[n - 1];
        int res = 0;
        for (int i = 0; i < n - 1; i++)
            if (s[i] != target) res++;
        cout << res << endl;
    }
    return 0;
}