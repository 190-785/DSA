#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n=1000;
    long long sum=0;
    for(int i=3;i<n;i++){
        if(i%3 ==0 || i%5==0) sum+=i;
    }
    cout<<sum;
    return 0;
}