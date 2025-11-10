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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            freq[a[i]]++;
        }
        if (freq.size() > 2)
        {
            cout << "NO" << endl;
        }
        else
        {
            if (freq.size() == 1)
            {
                cout << "YES" << endl;
            }
            else if (n % 2 == 0)
            {
                if (freq.begin()->second == n / 2 && next(freq.begin())->second == n / 2)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            else
            {
                if ((freq.begin()->second == n / 2 && next(freq.begin())->second == n / 2 + 1) || (freq.begin()->second == n / 2 + 1 && next(freq.begin())->second == n / 2))
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
        }
    }
    return 0;
}