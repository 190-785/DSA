#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        m = max(m, (int)arr[i].size());
    }
    for (int i = 0; i < n; i++)
    {
        string curr = arr[i];
        int currLen = curr.size();
        int k = (m - currLen) / 2;
        for (int j = 0; j < k; j++)
        {
            cout << ".";
        }
        cout << curr;
        for (int j = 0; j < k; j++)
        {
            cout << ".";
        }
        cout << endl;
    }
    return 0;
}
