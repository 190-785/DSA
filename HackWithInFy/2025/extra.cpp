#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    ll sum,pref,suff,best;
    node(){
        sum=pref=suff=best=0;
    }
    node(ll val){
        sum=val;
        pref=suff=best=max(0LL,val);
    }
};
vector<node> seg;
node mergeNodes(node left,node right){
    node res=node();
    res.sum=left.sum+right.sum;
    res.pref=max(left.pref,left.sum+right.pref);
    res.suff=max(right.suff,right.sum+left.suff);
    res.best=max({left.best,right.best,left.pref+right.suff});
    return res;
}
void build(ll idx,ll l,ll r,vector<int>& arr){
    if(l==r){
        seg[idx]=node(arr[l]);
        return;
    }
    ll mid=l+(r-l)/2;
    build(idx*2,l,mid,arr);
    build(idx*2+1,mid+1,r,arr);
    seg[idx]=mergeNodes(seg[idx*2],seg[idx*2+1]);
}
node query(ll idx,ll l,ll r,ll ql, ll qr){
    if(l>qr || r<ql) return node(0);
    if(l>=ql && r<=qr){
        return seg[idx];
    }
    ll mid=l+(r-l)/2;
    node left=query(idx*2,l,mid,ql,qr);
    node right=query(idx*2+1,mid+1,r,ql,qr);
    return mergeNodes(left,right);
}
void update(ll idx,ll l,ll r,ll pos,ll val){
    if(l==r){
        seg[idx]=node(val);
        return;
    }
    ll mid=l+(r-l)/2;
    if(pos<=mid){
        update(idx*2,l,mid,pos,val);
    }
    else{
        update(idx*2+1,mid+1,r,pos,val);
    }
    seg[idx]=mergeNodes(seg[idx*2],seg[idx*2+1]);
}
int main(){
    
}