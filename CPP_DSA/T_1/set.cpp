#include<bits/stdc++.h>

using namespace std;

int main()
{
    //Immutable,Sorted,unique, UnIndexed
    set<int>st1;//Ascending
    set<int,greater<int>>st2;//Descending
    st1.insert(1);
    st1.insert(31);
    st1.insert(2);
    st1.insert(1);
    cout<<"Size of st1: "<<st1.size()<<endl;
    for(auto it=st1.begin();it!=st1.end();it++){
        cout<<*it<<endl;
    }
    // auto it=st1.begin();
    // *it=120;
    //It follows BST TC_> O(LogN)

    set<int>s={1,2,3,4};

    //Find returns the address of the value if not present then iterator to the end
    
    cout<<*s.find(2)<<endl;
    cout<<s.count(1)<<endl;

    //Lower bound
    set<int> st3={1,3,4,62,13,6};
    cout<<*st3.lower_bound(5)<<endl;//Element or closest upper
    cout<<*st3.upper_bound(4)<<endl;//CLosest upper not that element
    cout<<*st3.upper_bound(66)<<endl;

}