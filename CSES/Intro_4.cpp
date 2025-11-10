#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long res=0;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int actPrev=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>actPrev){
            actPrev=arr[i];
        }
        else{
            res+=(actPrev-arr[i]);
        }
    }
    cout<<res;
    return 0;
}