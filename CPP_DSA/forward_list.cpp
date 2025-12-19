#include<bits/stdc++.h>
using namespace std;

int main(){
    forward_list<int> flist={1,2,3,4,5}//works like singly linked list
    flist.push_front(6);
    flist.pop_front();
    flist.insert_after(flist.begin()+1,131);//does not work since we cannot increase the iterator like this we have to mannually traverse it
    flist.insert_after(flist.begin(),,2,131);//2 iterations of 131
    

}