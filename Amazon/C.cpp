#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, n;
    cin >> x;
    cin >> n;
    if(n<2){
        cout<<0<<endl;
        return 0;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    long long res = 0;
    unordered_map<int, int> rems;
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        curr %= x;
        int reqRem = x - curr;
        auto it = rems.find(reqRem);
        if (it != rems.end())
        {
            res += it->second;
        }
        if (rems.find(curr) == rems.end())
            rems[curr] = 1;
        else
            rems[curr]++;
    }
    cout << res << endl;
    return 0;
}