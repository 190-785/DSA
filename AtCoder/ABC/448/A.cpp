#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < x)
        {
            x = arr[i];
            cout << 1 << endl;
        }
        else
            cout << 0 << endl;
    }
    return 0;
}