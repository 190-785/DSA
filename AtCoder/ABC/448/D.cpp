#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int parent, vector<vector<int>> &g, vector<int> &pNode)
{
    pNode[u] = parent;

    for (int v : g[u])
    {
        if (v == parent)
            continue;
        dfs(v, u, g, pNode);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<long long> A(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    vector<vector<int>> g(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> pNode(n + 1);

    dfs(1, -1, g, pNode);

    for (int k = 1; k <= n; k++)
    {
        unordered_set<long long> vis;
        bool duplicate = false;

        int cur = k;

        while (cur != -1)
        {
            if (vis.count(A[cur]))
            {
                duplicate = true;
                break;
            }

            vis.insert(A[cur]);
            cur = pNode[cur];
        }

        if (duplicate)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}