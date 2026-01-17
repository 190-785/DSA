#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        string b = s;
        sort(b.begin(), b.end());
        vector<int> idx;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != b[i])
                idx.push_back(i + 1);
        }
        if (idx.empty())
        {
            cout << "Bob" << endl;
        }
        else
        {
            cout << "Alice" << endl;
            cout << idx.size() << endl;
            for (int i = 0; i < idx.size(); i++)
            {
                if (i) cout << " ";
                cout << idx[i];
            }
            cout << endl;
        }
    }
    return 0;
}
