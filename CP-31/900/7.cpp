#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        int maxValid=0;
        int valid=0;
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1]<=k){
                valid++;
            }
            else{
                valid=0;
            }
            maxValid = max(maxValid, valid);
        }
        cout<<n-maxValid-1<<endl;
    }
    return 0;
}