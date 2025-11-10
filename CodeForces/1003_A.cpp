#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> testCases(n);
    for(int i=0;i<n;i++){
        cin>>testCases[i];
    }
    for(int i=0;i<n;i++){
        string us=testCases[i];
        us.pop_back();
        us.pop_back();
        cout<<us+'i'<<endl;
    }
    return 0;
}