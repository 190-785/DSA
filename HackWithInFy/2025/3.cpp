#include<bits/stdc++.h>
using namespace std;

int disturbances(int c,int ini,vector<int>&arr){
    int n=arr.size();
    int dis=0;
    for(int i=0;i<n;i++){
        if(arr[i]==-1){
            if(ini==0){
                dis++;
            }
            else{
                ini--;
            }
        }
        else{
            if(ini==c){
                dis++;
            }
            else{
                ini++;
            }
        }
    }
    return dis;
}

int main(){
    int n,c;
    cin>>n>>c;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int low=0,high=c;
    while(low<high){
        int mid=low+(high-low)/2;
        int curr=disturbances(c,mid,arr);
        int next=disturbances(c,mid+1,arr);
        if(next>=curr){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    cout<<low<<endl;
    return 0;
}