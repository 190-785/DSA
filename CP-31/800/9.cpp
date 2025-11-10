#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> a(n-1);
        for(int i=0;i<n-1;i++) cin>>a[i];
        int res=accumulate(a.begin(),a.end(),0);
        cout<<-res<<endl;
    }
    return 0;
}
