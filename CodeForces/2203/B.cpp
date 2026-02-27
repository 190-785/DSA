#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x;
        cin >> x;
        string num = to_string(x);
        int n = num.size();
        vector<int> digits(n);
        int currSum = 0;
        for (int i = 0; i < n; i++)
        {
            digits[i] = num[i] - '0';
            currSum += digits[i];
        }

        int res = n;
        for (int s = 1; s <= 9; s++)
        {
            int diff = currSum - s;
            int moves = 0;
            if (diff > 0)
            {
                vector<int> dec;
                for (int i = 0; i < n; i++)
                {
                    if (i == 0 && n > 1)
                        dec.push_back(digits[i] - 1);
                    else
                        dec.push_back(digits[i]);
                }
                sort(dec.rbegin(), dec.rend());
                int rem = diff;
                for (int i = 0; i < n && rem > 0; i++)
                {
                    if (dec[i] <= 0)
                        continue;
                    rem -= dec[i];
                    moves++;
                }
                if (rem > 0)
                    moves = n;
            }
            else if (diff < 0)
            {
                vector<int> inc;
                for (int i = 0; i < n; i++)
                {
                    inc.push_back(9 - digits[i]);
                }
                sort(inc.rbegin(), inc.rend());
                int rem = -diff;
                for (int i = 0; i < n && rem > 0; i++)
                {
                    if (inc[i] <= 0)
                        continue;
                    rem -= inc[i];
                    moves++;
                }
                if (rem > 0)
                    moves = n;
            }
            res = min(res, moves);
        }
        cout << res << endl;
    }
    return 0;
}