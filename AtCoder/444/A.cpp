#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int first=n%10;
  n/=10;
  int sec=n%10;
  n/=10;
  if(first==sec && sec==n) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}