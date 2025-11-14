#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;

    while (t--)
    {
        string n;
        cin >> n;

        vector<string> possibleValues = {"00", "25", "50", "75"};
        int ans = INT_MAX;

        for (auto possibleValue : possibleValues)
        {
            int operations = 0;
            int checkerIndex = possibleValue.size() - 1;

            for (int i = n.size() - 1; i >= 0; i--)
            {
                if (n[i] == possibleValue[checkerIndex])
                {
                    checkerIndex--;
                    if (checkerIndex < 0)
                        break;
                }
                else
                    operations++;
            }

            if (checkerIndex >= 0)
                operations = INT_MAX;

            ans = min(ans, operations);
        }

        cout << ans << endl;
    }

    return 0;
}
