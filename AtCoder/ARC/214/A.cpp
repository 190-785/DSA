#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> mat(n, vector<char>(n));
    vector<int> req(2 * n + 2, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] != '?')
            {
                int s = i + j + 2;
                int d = mat[i][j] - '0';
                if (req[s] == -1)
                {
                    req[s] = d;
                }
                else if (req[s] != d)
                {
                    cout << "-1" << endl;
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int s = i + j + 2;
            if (req[s] == -1)
                cout << 0;
            else
                cout << req[s];
        }
        cout << endl;
    }
    return 0;
}