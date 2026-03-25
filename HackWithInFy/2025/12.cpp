#include <bits/stdc++.h>
using namespace std;
vector<int> seg;
int lim;
vector<int>findDivisors(int n){
    vector<int> divs;
    
    for(int i=1;i<i*i<=n;i++){
        if(n%i==0){
            if(i<=lim)
            divs.push_back(i);
        }
        if(n/i!=i){ 
            if(n/i<=lim)
            divs.push_back(n/i);}
    }
    return divs;
}

void build(int idx,int l,int r,vector<int>& bonus){
    if(l==r){
        seg[idx]=bonus[l];
        return ;
    }
    int mid=(l+r)/2;
    build(idx*2,l,mid,bonus);
    build(idx*2+1,mid+1,r,bonus);
    seg[idx]=max(seg[idx*2],seg[idx*2+1]);
}

int query(int idx,int l,int r,int ql,int qr){
    if(l>qr || r<ql) return 0;
    if(l>=ql && r<=qr){
        return seg[idx];
    }
    int mid=(l+r)/2;
    return max(query(idx*2,l,mid,ql,qr),query(idx*2+1,mid+1,r,ql,qr));
}

int main()
{
    int n;
    cin >> n;
    lim=n/2;
    vector<int> arr(n);
    vector<int> bonus(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        cin >> bonus[i];
    seg.assign(4*n,0);
    long long totalXP=0;
    build(1,0,n-1,bonus);
    vector<int> lastSeen(n/2,n);
    for(int i=n-1;i>=0;i--){
        int val=arr[i];
        vector<int> div=findDivisors(val);
        int mulNumIdx=-1;
        for(int j=i+1;j<n;j++){
            if(arr[j]%arr[i]==0){
                mulNumIdx=j;
                break;
            }
        }
        if(mulNumIdx!=-1){
            int xp=query(1,0,n-1,i,mulNumIdx);
            totalXP+=xp;
        }
        for(int x:div){
            lastSeen[x-1]=i;
        }
    }
    cout<<totalXP<<endl;
    return 0;
}