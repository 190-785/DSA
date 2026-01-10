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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (arr[0] == 0 && arr[n - 1] == 0)
            cout << "Bob"<<endl;
        else
            cout << "Alice"<<endl;
    }
    return 0;
}
