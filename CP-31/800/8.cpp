#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int j=0;j<n;j++) cin>>a[j];
        for(int i=0;i<n;i++){
            if(a[i]==k){
                cout<<"YES"<<endl;
                goto end;
            }
        }
        cout<<"NO"<<endl;
        end:;
    }
    return 0;
}
