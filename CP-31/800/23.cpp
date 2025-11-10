#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int sX, sY, dX, dY;
        cin >> sX >> sY >> dX >> dY;

        if (dY < sY)
        {
            cout << -1 << endl;
            continue;
        }

        int moves = dY - sY;
        sX += moves;

        if (sX < dX)
        {
            cout << -1 << endl;
            continue;
        }

        moves += (sX - dX);
        cout << moves << endl;
    }
    return 0;
}
