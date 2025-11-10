#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, -1, 1}, dy[4] = {-1, -1, 1, 1};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long xKing, yKing;
        cin >> xKing >> yKing;
        long long xQueen, yQueen;
        cin >> xQueen >> yQueen;

        set<pair<int, int>> kingHits, queenHits;

        for (int j = 0; j < 4; j++)
        {
            kingHits.insert({xKing + dx[j] * a, yKing + dy[j] * b});
            kingHits.insert({xKing + dx[j] * b, yKing + dy[j] * a});

            queenHits.insert({xQueen + dx[j] * a, yQueen + dy[j] * b});
            queenHits.insert({xQueen + dx[j] * b, yQueen + dy[j] * a});
        }

        int ans = 0;
        for (auto position : kingHits)
            if (queenHits.find(position) != queenHits.end())
                ans++;

        cout << ans << endl;
    }
    return 0;
}
