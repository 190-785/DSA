#include<bits/stdc++.h>
using namespace std;
int main()
{
    //Unique and Unsorted

    //Upperbound and lowerbound does not work in it
    unordered_set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(12);
    st.insert(3);
    st.insert(1);
    cout<<st.size()<<endl;
    for(auto it=st.begin();it!=st.end();it++){
        cout<<*it<<" ";
    }
}