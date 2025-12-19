#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    st.push(12);
    st.push(6);
    // Iterators will not work
    cout << st.top() << endl;
    st.push(123);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.empty() << endl;
    cout << st.size() << endl;

    stack<int> st2;
    st2.push(10);
    st2.push(20);
    cout << st2.top() << endl;
    st.swap(st2);
    cout << st.top() << endl;
}