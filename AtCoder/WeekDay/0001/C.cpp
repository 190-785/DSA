#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    if (k >= n)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    long long res=0;
    for(int i=0;i<n-k;i++){
        res+=arr[i];
    }
    cout<<res<<endl;
    return 0;
}