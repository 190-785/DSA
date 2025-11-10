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
        int maxValid = 1;
        int currValid = 1;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == s[i + 1])
            {
                currValid++;
            }
            else
            {
                maxValid = max(maxValid, currValid);
                currValid = 1;
            }
        }
        if(s[n-1]==s[n-2])
        maxValid = max(maxValid, currValid);
        cout << maxValid + 1 << endl;
    }
    return 0;
}