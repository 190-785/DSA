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
        vector<int> arr;
        cin >> n >> s;
        int l = 0;
        int r = n - 1;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                ++l;
                --r;
            }
            else if (s[l] == '0' && s[r] == '1')
            {
                arr.push_back(r + 1);
                --r;
            }
            else
            {
                arr.push_back(l + 1);
                ++l;
            }
        }
        sort(arr.begin(), arr.end());
        cout << arr.size() << endl;
        if (arr.size() >= 0)
        {
            for (int i = 0; i < (int)arr.size(); ++i)
            {
                if (i)
                    cout << arr[i]<<" ";
            }
        }
        cout << endl;
    }
    return 0;
}
