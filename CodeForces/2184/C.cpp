#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        if (n == k)
        {
            cout << 0 << endl;
            continue;
        }
        vector<long long> currPiles;
        currPiles.push_back(n);
        int mins = 0;
        bool found = false;

        while (!currPiles.empty())
        {
            mins++;
            vector<long long> nextPiles;

            for (int i = 0; i < currPiles.size(); i++)
            {
                long long val = currPiles[i];
                long long part1 = val / 2;
                long long part2 = (val + 1) / 2;

                if (part1 == k || part2 == k)
                {
                    found = true;
                    break;
                }

                if (part1 > k)
                    nextPiles.push_back(part1);
                if (part2 > k)
                    nextPiles.push_back(part2);
            }
            if (found)
                break;
            sort(nextPiles.begin(), nextPiles.end());
            nextPiles.erase(unique(nextPiles.begin(), nextPiles.end()), nextPiles.end());
            currPiles = nextPiles;
        }

        if (found)
            cout << mins << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}