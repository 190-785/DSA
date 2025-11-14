#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int freqZero=0,freqOne=0;
        for(int i=0;i<n;i++){
            if(a[i]==0) freqZero++;
            else if (a[i]==1) freqOne++;
        }
        long long res=pow(2,freqZero)*freqOne;
        cout<<res<<endl;
    }
    return 0;
}