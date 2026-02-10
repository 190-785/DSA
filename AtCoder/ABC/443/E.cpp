#include <bits/stdc++.h>
using namespace std;

int main()
{   //TLE even at 4k ms
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<string> grid(n);
        for (int i = 0; i < n; i++)
            cin >> grid[i];

        vector<vector<int>> allowed(n, vector<int>(n, 0));
        allowed[n - 1][c - 1] = 1;

        vector<vector<int>> emptyBelow(n, vector<int>(n, 0));
        for (int col = 0; col < n; col++)
        {
            emptyBelow[n - 1][col] = (grid[n - 1][col] == '.');
            for (int row = n - 2; row >= 0; row--)
            {
                emptyBelow[row][col] = emptyBelow[row + 1][col] & (grid[row][col] == '.');
            }
        }

        for (int row = n - 1; row > 0; row--)
        {
            for (int col = 0; col < n; col++)
            {
                if (!allowed[row][col])
                    continue;
                for (int dcol = -1; dcol <= 1; dcol++)
                {
                    int ncol = col + dcol;
                    int nrow = row - 1;
                    if (ncol < 0 || ncol >= n)
                        continue;
                    if (grid[nrow][ncol] == '.')
                        allowed[nrow][ncol] = 1;
                    else
                    {
                        if (emptyBelow[nrow + 1][ncol])
                        {
                            allowed[nrow][ncol] = 1;
                            grid[nrow][ncol] = '.';
                            for (int k = nrow; k >= 0; k--)
                                emptyBelow[k][ncol] = (grid[k][ncol] == '.') & (k == n - 1 ? 1 : emptyBelow[k + 1][ncol]);
                        }
                    }
                }
            }
        }
        string res(n, '0');
        for (int col = 0; col < n; col++)
            if (allowed[0][col])
                res[col] = '1';
        cout << res << endl;
    }
}
