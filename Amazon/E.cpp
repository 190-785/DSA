#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<string> patterns(n);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        patterns[i]=s;
    }
    int res=0;
    for(int j=0;j<m;j++){
        char curr=patterns[i][j];
        for(int i=1;i<n;i++){
            if(patterns[i][j]==curr || patterns[i][j]=='?'){
                
            }
        }
    }
}