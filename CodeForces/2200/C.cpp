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
        vector<char> stk;
        for (char c : s)
        {
            if (!stk.empty() && stk.back() == c)
                stk.pop_back();
            else
                stk.push_back(c);
        }
        if (stk.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}