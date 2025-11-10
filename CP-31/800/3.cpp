#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int res=0;
        int consecutive=0;
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                consecutive=0;
                continue;
            }
            else{
                consecutive++;
                if(consecutive==3) break;
                res++;
            }
        }
        if(consecutive==3) res=2;
        cout<<res<<endl;
    }
    return 0;
}
