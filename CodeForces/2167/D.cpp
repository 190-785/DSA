#include<bits/stdc++.h>
using namespace std;
int main(){
    const int LMT=200000;
    vector<bool> isPrime(LMT+1,true);
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=LMT;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=LMT;j+=i){
                isPrime[j]=false;
            }
        }
    }
    vector<long long> prime;
    for(int i=2;i<=LMT;i++){
        if(isPrime[i]){
            prime.push_back(i);
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long g=0;
        for(int i=0;i<n;i++){
            long long x;
            cin>>x;
            g=std::gcd(g,x);
        }
        long long res=-1;
        for(auto p:prime){
            if(g%p!=0) {
                res=p;
                break;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}