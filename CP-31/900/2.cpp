#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        int oddCount = 0;
        for (int count : freq)
        {
            if (count % 2 != 0)
                oddCount++;
        }
        int rem = n - k;
        if (rem % 2 == 0) {
            if (oddCount <= k) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            if (oddCount - 1 <= k) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
