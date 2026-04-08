#include<bits/stdc++.h>
using namespace std;

struct segTree{
    int size;
    vector<int> seg;
    segmentTree(int n){
        size=n;
        seg.assign(4*n,0);
    }
    void update(int idx,int l,int r,int i,int val){
        if(l==r){
            seg[i]=max(seg[i],val);
        }
    }
}

int main(){
    
}