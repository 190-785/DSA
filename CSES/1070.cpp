#include<bits/stdc++.h>
using namespace std;    

int main(){
    int n;
    cin>>n;
    if(n<4){
        if(n==1) cout<<1<<endl;
        else{
            cout<<"NO SOLUTION"<<endl;
        }
    }
    else{
        for(int i=2;i<=n;i+=2){
            cout<<i<<" ";
        }
        for(int i=1;i<=n;i+=2){
            cout<<i<<" ";
        }
    }
    return 0;
}
