#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string a, b, c;
    cin >> a >> b >> c;
    if (a == c || b == c)
        return -1;
    string regex;
    bool flag = false;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == c[i] || b[i] == c[i])
        {
            string curr = "[";
            for (int i = 0; i < 26; i++)
            {
                curr += ("A" + i);
            }
            curr += "]";
            regex.insert(regex.begin(), curr);
        }
        else if (a[i] != c[i] && b[i] != c[i])
        {
            string curr = "[";
            for (int i = 0; i < 26; i++)
            {
                if (!flag && c[i] == "A" + i)
                {
                    flag = true;
                    continue;
                }
                curr += ("A" + i);
            }
            curr += "]";
            regex.insert(regex.begin(), curr);
        }
    }
    cout<<regex<<endl;
    return 0;
}