#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n,q;
        cin >> n>>q;
        vector<long long>arr(n);
        for(long long i=0;i<n;i++) cin>>arr[i];
        vector<long long> prefix(n+1,0);
        prefix[0]=0;
        for(long long i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+arr[i-1];
        }
        while(q--){
            long long l,r,k;
            cin>>l>>r>>k;
            long long left=prefix[l-1];
            long long right=prefix[r];
            long long rmv=right-left;
            long long add=(r-l+1)*k;
            long long total=prefix[n]-rmv+add;
            if(total%2==1) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        
    }
    return 0;
}