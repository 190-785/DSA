#include <iostream>
#include <vector>
#include <numeric>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long m;
        cin >> n >> m;

        vector<vector<int>> p(m);
        for (int i = 0; i < n; ++i)
        {
            int l;
            cin >> l;
            for (int k = 0; k < l; ++k)
            {
                int e;
                cin >> e;
                p[e - 1].push_back(i);
            }
        }

        set<vector<int>> constraints;
        bool possible = true;
        for (int i = 0; i < m; ++i)
        {
            if (p[i].empty())
            {
                possible = false;
                break;
            }
            sort(p[i].begin(), p[i].end());
            constraints.insert(p[i]);
        }

        if (!possible)
        {
            cout << "NO" << endl;
            continue;
        }

        vector<bool> forced(n, false);
        for (const auto &c : constraints)
        {
            if (c.size() == 1)
            {
                forced[c[0]] = true;
            }
        }

        bool hasComplex = false;
        int realEdges = 0;
        for (const auto &c : constraints)
        {
            bool trivial = false;
            for (int u : c)
            {
                if (forced[u])
                {
                    trivial = true;
                    break;
                }
            }
            if (!trivial)
            {
                if (c.size() >= 3)
                {
                    hasComplex = true;
                    break;
                }
                if (c.size() == 2)
                {
                    realEdges++;
                }
            }
        }

        if (hasComplex || realEdges > 0)
        {
            cout << "YES" << endl;
            continue;
        }

        int count = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!forced[i])
            {
                count++;
            }
        }

        if (count >= 2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}