#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> invasion(n);
    for (int i = 0; i < n; i++)
        cin >> invasion[i];
    queue<pair<int, int>> q;
    int enemies = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (invasion[i][j] == 'A')
            {
                q.push({i, j});
                vis[i][j] = true;
            }
            else if (invasion[i][j] == 'E')
                enemies++;
        }
    }
    if (enemies == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    int time = 0;
    while (!q.empty() && enemies>0)
    {
        int len = q.size();
        while (len--)
        {
            auto [r, c] = q.front();
            q.pop();
            for (auto it : dirs)
            {
                int nr = r + it[0];
                int nc = c + it[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m)
                {
                    if (invasion[nr][nc] == 'E')
                    {
                        if (!vis[nr][nc])
                        {
                            q.push({nr, nc});
                            invasion[nr][nc] = 'A';
                            // cout<<nr<<" "<<nc<<endl;
                            enemies--;
                            vis[nr][nc] = true;
                        }
                    }
                }
            }
        }
        time++;
    }
    if (enemies != 0)
        cout << -1 << endl;
    else
        cout << time << endl;
    return 0;
}