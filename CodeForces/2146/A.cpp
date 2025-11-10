#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        map<int, int> freqMap;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            freqMap[x]++;
        }

        vector<int> freq;
        for (auto const &pair : freqMap)
            freq.push_back(pair.second);
        int maxLen = 0;

        for (int k = 1; k <= n; k++)
        {
            int distElCount = 0;

            for (int f : freq)
            {
                if (f >= k)
                    distElCount++;
            }

            int curr = distElCount * k;

            maxLen = max(maxLen, curr);
        }

        cout << maxLen << endl;
    }

    return 0;
}