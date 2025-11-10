#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n-1;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    bool flag=true;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=i){
            cout<<i;
            flag=false;
            break;
        }
    }
    if(flag) cout<<n;

    return 0;
}