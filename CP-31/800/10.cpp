#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<char>> grid(10, vector<char>(10));
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cin >> grid[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (grid[i][j] == 'X')
                {
                    int dist = min({i, j, 9 - i, 9 - j});
                    res += dist + 1;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}