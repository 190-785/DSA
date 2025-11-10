#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int oddCnt=0;
        for(int i=0;i<n;i++){
            if(a[i]%2!=0) oddCnt++;
        }
        if(oddCnt%2==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}