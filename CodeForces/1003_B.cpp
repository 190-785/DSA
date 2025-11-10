#include<bits/stdc++.h>
using namespace std;

int main(){
    /*Note that if you can ever do an operation, the answer is 1
. This is because once you've done an operation on a string of length k, you are free to choose any character to replace si with. Therefore, if you replace si either with the character directly before it, or the character directly after it, you will end up with a string with length k−1
 upon which you can do an operation again. Therefore, by induction, it's clear that you can keep operating on the string until only one character remains.

However, if you cannot perform any operations, the answer is |s|
, because you have not modified the original string.

Therefore, the answer is 1
 if si=si+1
 for some i
, or n
 otherwise.*/
    int n;
    cin>>n;
    vector<string> testCases(n);
    for(int i=0;i<n;i++){
        cin>>testCases[i];
    }
    for(int i=0;i<n;i++){
        string case1=testCases[i];
        int len=case1.size();
        if(len==1) cout<<"1"<<endl;
        else{
            bool flag=true;
        for(int j=1;j<len;j++){
            if(case1[j-1]==case1[j]){
                cout<<"1"<<endl;
                flag=false;
                break;
            }
        }
        if(flag) cout<<len<<endl;
        }
    }
    return 0;
}