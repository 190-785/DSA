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
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];
        //You make me feel invincible
        //You can't touch me now
        //Any Skillet fans here? Hit me up!
        int cntNonZero = 0;
        int totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i] != 0)
                cntNonZero++;
            totalSum += b[i];
        }
        cout << min(cntNonZero, totalSum - n + 1) << endl;
    }
    return 0;
}