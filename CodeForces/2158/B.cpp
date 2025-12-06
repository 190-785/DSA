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
        int nTwo = 2 * n;
        vector<int> freq(nTwo + 1, 0);

        for (int i = 0; i < nTwo; ++i)
        {
            int a;
            cin >> a;
            ++freq[a];
        }

        int oddCntDist = 0;
        int evenCntDist = 0;
        for (int i = 1; i <= nTwo; i++)
        {
            if (freq[i] == 0)
                continue;
            if (freq[i] % 2 == 1)
                oddCntDist++;
            else
                evenCntDist++;
        }

        int k = min(evenCntDist, n);
        if (oddCntDist == 0 && (k % 2) != (n % 2))
        {
            k--;
        }
        if (k < 0)
            k = 0;

        cout << oddCntDist + 2 * k << endl;
    }
    return 0;
}
