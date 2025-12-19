// #include<iostream>
#include<bits/stdc++.h>
// #include<vector>
using namespace std;

void printV(vector<char>v){
    for(auto it:v){
        cout<<it<<" ";
    }
    cout<<endl;
}

int main(){
    // vector<int>vec;
    // vec.push_back(12);
    // vec.push_back(23);


    vector<int>v1={1,2,3,4};
    v1.push_back(23);

    vector<int>v2(53,100);  //vector<int>v2{size,value};
    cout<<v2[31];

    //Iteraotr: begin(), end()
    vector<int>v5(v1.begin(),v1.end());
    cout<<endl<<v5[4]<<endl;
    vector<int>v6(12);
    fill(v6.begin(),v6.end(),11); //Similar to //vector<int>v2{size,value);

    //Works similar to fill() just that the values in iota are filled in increasing order

    iota(v6.begin(),v6.end(),11);
    cout<<v6[1]<<endl;

    //Accessing values in a vector

    cout<<v6.at(2)<<" ";//Essentially index
    cout<<v6.front()<<" "; //Front value peek
    cout<<v6.back()<<" "; //Last value peek

    cout<<*(v6.begin()+3)<<endl; // Value at addredd of 3+first index


    //Traversing

    // for(int i=0;i<v6.size();i++){
    //     cout<<vec[i]<<" ";
    // }
    
    for(auto i:v6){
        cout<<i<<" ";
    }
    
    // for(auto it=v6.begin();it!=vec.end();it++){
    //     cout<<*(it)<<" ";
    // }


    //rbegin(),,rend();
    for(auto i=v6.rbegin();i!=v6.rend();i++){ //traverse in reverse
        cout<<*i<<" ";
    }
    cout<<endl;
    if(v6.empty()){
        cout<<"true";
    }
    else{
        cout<<"false"<<endl;
    }

    //Insertion & Deletion

    vector<char> veca={'a','b','c'};
    printV(veca);
    veca.pop_back();
    printV(veca);

    veca.insert(veca.end()-2,'d');
    
    vector<char> v8;
    auto first=v8.begin()+1;
    auto second=v8.begin()+3;
    v8.insert(veca.begin(),first,second);
    cout<<v8[1]<<" ";
    veca.erase(veca.begin()+1);
    reverse(veca.begin(), veca.end());

    veca.reverse(veca.begin(),veca.end());

    sort(veca.begin(),veca.end(),greater<>());

    //cbegin(), cend(), crbegin(), crend(); Does not allow you to do any changes ot the vector(constant) when using these functions


return 0;
}