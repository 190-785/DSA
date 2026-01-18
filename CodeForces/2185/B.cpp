#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        int maxNum=0;
        for(int i=0;i<n;i++){ 
            cin>>a[i];
            maxNum=max(maxNum,a[i]);
        }
        cout<<maxNum*n<<endl;
    }
    return 0;
}