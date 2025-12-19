#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Works on key value pair
    //No duplicate keys allowed
    //Map is sorted by keys

    map<int,int>mpp;
    mpp.insert({1,2});
    mpp.insert({2,21});
    mpp.insert({12,21});
    //By default map is based pairs {in background it uses a pair of key and vlaue}
    mpp[3]=13;
    for(auto it:mpp){
        cout<<it.first<<"->"<<it.second<<"/";
    }
    cout<<endl<<mpp.size()<<endl;

    //In multimap dublicate keys are allowed but still will be sorted
     
    multimap<int,int>mp;
    mp.insert({1,2});
    mp.insert({2,21});
    mp.insert({12,21});
    mp.insert({1,231});
    mp.insert({2,2141});
    mp.insert({12,212});

    for(auto it:mp){
        cout<<it.first<<"->"<<it.second<<"/";
    }
    cout<<endl<<mp.size()<<endl;
    //If traversing using itrator
    auto it=mp.begin();
    cout<<it->first<<endl;//Need to use -> not .

    //Unordered map-> not sorted but still unique keys

    unordered_map<int,int>um;
    um.insert({1,2});
    um.insert({2,21});
    um.insert({12,21});
    um.insert({1,231});
    um.insert({2,2141});
    um.insert({12,212});
    
    um.insert(make_pair(41,33));
    for(auto it:mp){
        cout<<it.first<<"->"<<it.second<<"/";
    }

    //Unordered multimap
    //Dublicate + Unsorted

}