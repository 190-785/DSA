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
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a.begin(),a.end());
        int minEl=a[0];
        int maxEl=a[n-1];
        if(minEl==maxEl){
            cout<<-1<<endl;
        }
        else{
            vector<int> b,c;
            int j=0;
            for(j=0;j<n;j++){
                if(a[j]!=maxEl) b.push_back(a[j]);
                else break;
            }
            c.insert(c.begin(),n-j,maxEl);
            cout<<b.size()<<" "<<c.size()<<endl;
            for(auto x:b)
                cout<<x<<" ";
            cout<<endl;
            for(auto x:c)
                cout<<x<<" ";
            cout<<endl;
        }
    }
    return 0;
}