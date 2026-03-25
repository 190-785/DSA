#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;

int find(int n){
    int sum=1;
    int base=2;
    while(n>0){
        if(n%2==1){
            sum=(sum*base)%MOD;
        }
        base=(base*base)%MOD;
        n/=2;
    }
    return sum;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    sort(a.rbegin(),a.rend());
    sort(b.begin(),b.end());
    long long res=0;
    for(int i=0;i<n;i++){
        res=((res*find(a[i]))%MOD + find(a[i])-1)%MOD;
        res=(res*find(b[i]))%MOD;
    }
    cout<<res<<endl;
    return 0;
}