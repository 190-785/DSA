#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,d;
        cin>>n>>m>>d;
        int maxHeight = d/m + 1;
        int totalTowers = (n + maxHeight - 1) / maxHeight;
        cout<<totalTowers<<endl;
    }
    return 0;
}