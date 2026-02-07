#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int res=0;
    for(int i=1;i<=n;i++){
        int currSum=0;
        int currNum=i;
        while(currNum){
            currSum+=(currNum%10);
            currNum/=10;
        }
        if(currSum==k) res++;
    }
    cout<<res<<endl;
    return 0;
}