#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> arr(n);
    int maxScore = -1;
    int maxScoreId = -1;
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= l && arr[i] <= r)
        {
            if (arr[i] > maxScore)
            {
                maxScore = arr[i];
                maxScoreId = i + 1;
            }
        }
    }
    cout << maxScoreId << endl;
    return 0;
}