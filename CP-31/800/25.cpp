#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin>>n;
        cin>>s;
        int res=n;
        int l=0,r=n-1;
        while(l<r){
            if(s[l]!=s[r]){
                l++;
                r--;
                res-=2;
            }
            else{
                break;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
