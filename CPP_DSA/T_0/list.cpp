#include<bits/stdc++.h>
using namespace std;

    void print()

int main(){

    list<int>ls;

    ls.push_back(1);
    ls.push_back(42);
    ls.pop_back();
    ls.push_front(33);
    ls.pop_front();
    //removes all iterations of 3;
    ls.remove(3);
    return 0;;
}