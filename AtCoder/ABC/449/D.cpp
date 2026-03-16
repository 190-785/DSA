#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll l,r,d,u;
    cin>>l>>r>>d>>u;
    ll res=0;
    for(ll x=l;x<=r;x++){
        ll ax=abs(x);
        ll low=max(d,-ax);
        ll high=min(u,ax);

        if(ax%2==0){
            if(high>=low) res+=high-low+1;
        }

        if(d<(-ax)){
            ll a=d;
            ll b=min(u,-ax-1);

            if(a%2) a++;
            if(b%2) b--;

            if(a<=b) res+=(b-a)/2+1;
        }
        if(u>ax){
            ll a=max(d,ax+1);
            ll b=u;
            if(a%2) a++;
            if(b%2) b--;
            if(a<=b) res+=(b-a)/2+1;
        }
    }
    cout<<res<<endl;
    return 0;
}