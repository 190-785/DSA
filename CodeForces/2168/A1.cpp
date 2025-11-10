#include<bits/stdc++.h>
using namespace std;

void firstRun(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    string res;
    for(int i=0;i<n;i++){
        res += char('a' + arr[i] - 1);
    }
    cout<<res<<endl;
}

void secondRun(){
    string s;
    cin>>s;
    cout<<s.size()<<endl;
    for(char &c:s){
        cout<<(int(c) - 'a' + 1)<<" ";
    }
    cout<<endl;
}

int main(){
    string run;
    cin>>run;
    if(run=="first") firstRun();
    else secondRun();
    return 0;
}