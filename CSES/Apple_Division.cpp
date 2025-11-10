#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    int diff=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        diff=min(diff,nums[i]);
    }
    cout<<diff;
    return 0;

}