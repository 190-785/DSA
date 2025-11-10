#include<bits/stdc++.h>
using namespace std;

int getFibonacci(int n){
    if(n<=1) return n;
    cout<<n<<endl;
    return getFibonacci(n-1)+getFibonacci(n-2);
}

int main(){
    int n=5;
    cout<<getFibonacci(n)<<endl;
}