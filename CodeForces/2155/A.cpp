#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int winners = n;
        int losers = 0;
        int total = 0;
        while (winners > 1 || losers > 1)
        {
            int matchesW = winners / 2;
            int matchesL = losers / 2;
            total += matchesW + matchesL;
            int newWinners = matchesW + (winners % 2);
            int newLosers = (winners / 2) + (losers / 2) + (losers % 2);
            winners = newWinners;
            losers = newLosers;
        }
        total += 1;
        cout << total << endl;
    }
    return 0;
}