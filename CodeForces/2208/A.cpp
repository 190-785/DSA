#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> freq(n*n+1,0);
        int maxFreq = 0;
        for(int i=0;i<n*n;i++){
            int x;
            cin >> x;
            freq[x]++;
            maxFreq = max(maxFreq,freq[x]);
        }

        if(maxFreq > n*(n-1))
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
}