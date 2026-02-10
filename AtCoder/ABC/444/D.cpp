#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> res;
    sort(a.begin(), a.end());

    int idx = 0;
    long long carry = 0;

    for (int i = 0; idx < n || carry; i++)
    {
        while (idx < n && a[idx] <= i)
            idx++;
        carry += (n - idx);
        res.push_back(carry % 10);
        carry /= 10;
    }

    reverse(res.begin(), res.end());
    if(res[0]!=0) cout<<res[0];
    for(size_t i=1;i<res.size();i++) cout<<res[i];
    cout << endl;
    return 0;
}