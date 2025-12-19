#include<bits/stdc++.h>
using namespace std;

int main()
{
    multiset<int> st;
    st.insert(1);
    st.insert(12);
    st.insert(1);
    st.insert(1);
    st.insert(1);
    st.insert(1);
    st.insert(31);
    cout<<st.size()<<endl;
    for(auto it=st.begin();it!=st.end();it++){
        cout<<*it<<" ";
    }
    cout<<st.count(1)<<endl;
    st.erase(st.find(1));
    for(auto it=st.begin();it!=st.end();it++){
        cout<<*it<<" ";
    }
    //st.erase(st.find(2),st.find()+2); Does not work since set is unindexed
    
}