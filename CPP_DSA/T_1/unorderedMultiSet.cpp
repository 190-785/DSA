#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_multiset<int> st;
    st.insert(1);
    st.insert(31);
    st.insert(1);
    st.insert(2);
    st.insert(12);
    st.insert(3);
    st.insert(2);
    st.insert(1);

    for(auto it=st.begin();it!=st.end();it++){
        cout<<*it<<" ";
    }
    
}