#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long test;
    cin >> test;
    while (test--)
    {
        string s, t;
        cin >> s >> t;

        int n = s.size();
        int m = t.size();

        vector<int> freqT(26, 0);
        for (int i = 0; i < m; i++)
            freqT[t[i] - 'A']++;

        for (int i = n - 1; i >= 0; i--)
        {
            if (freqT[s[i] - 'A'] > 0)
                freqT[s[i] - 'A']--;
            else
                s[i] = '.';
        }

        string finalString = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '.')
                finalString += s[i];
        }

        if (finalString == t)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
