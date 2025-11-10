#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    int maxRep=1;
    int rep=1;
    for(int i=1;i<str.size();i++){
        if(str[i]==str[i-1]){
            rep++;
            maxRep=max(maxRep,rep);
        }
        else{
            rep=1;
        }
    }
    cout<<maxRep;
    return 0;
}