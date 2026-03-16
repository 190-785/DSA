#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    vector<vector<int>> locs(26);
    for (int i = 0; i < n; i++)
    {
        locs[s[i] - 'a'].push_back(i);
    }
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        auto &vec = locs[s[i] - 'a'];

        int left = i + l;
        int right = i + r;
        auto it1 = lower_bound(vec.begin(), vec.end(), left);
        auto it2 = upper_bound(vec.begin(), vec.end(), right);
        res += it2 - it1;
    }
    cout << res << endl;
    return 0;
}