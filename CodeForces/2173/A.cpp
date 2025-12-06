#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        int sleep = 0;
        int awake = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                awake = max(awake, i + k);
            if (i > awake)
                sleep++;
                }
        cout << sleep << endl;
    }
    return 0;
}