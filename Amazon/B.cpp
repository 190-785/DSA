#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    unordered_map<int,int> freq;
    long long sum=0;
    for(int i=0;i<n;i++){
        if(freq.find(arr[i])==freq.end()){
            freq[arr[i]]=1;
            sum+=arr[i];
        }
        else{
            int currFreq=freq[arr[i]];
            freq[arr[i]]++;
            sum+=(ceil(arr[i]/(pow(2,currFreq))));
        }
    }
    cout<<sum<<endl;
}


