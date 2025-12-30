#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int hasY=0;
        for(int i=0;i<n;i++){
            if(s[i]=='Y') hasY++;
        }

        cout << (hasY>1 ? "NO\n" : "YES\n");
    }
    return 0;
}
