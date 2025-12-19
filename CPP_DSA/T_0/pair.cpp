#include<iostream>

using namespace std;
int main()
{
    cout<<"LIght"<<endl;

    pair<int,int> pr;
    pr={1,2};
    pair pr2(13,'Y');
    cout<<pr.first<<" "<<pr.second;
    cout<<pr2.second<<" ";
    pair s(pr2);
    cout<<s.first;
    pair<int,char>q;
    
    cout<<q.second<<endl;
    pair<int,pair<int,int>>nes_pair={12,{31,41}};
    cout<<nes_pair.second.first;
    pair<int,int> p1={234,414};
    pair<int,int>p2={4,5};
    p1.swap(p2);
    cout<<p1.second<<p2.first;
    pair<int,int>arr[2];
    arr[0]={1,2};
    
    return 0;
}

