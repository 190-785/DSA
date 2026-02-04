#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> L(n);
    for(int i=0;i<n;i++) cin>>L[i];
    //Explanation->
        /*
            //Non- constructible change question
            (2D-1)->    1 3 5 7 9  [ For Perfect Squares ]
            (n^2-2) [ These numbers cannot be formed without taking extra days ] 
            [ 2 literally cannot be formed ]
            1 [2] 3 4 5 6 [7] 8 9 10 11 12 13 [14] 15 16 17 18 19 20 21 22 [23] 24 25 26 27 28 29 30 [34] 35 36 37 38 39 40 41 42 43 44 45 46 [47] 48 49
            O(N) Solution -> 3rd ques is Medium Level

        */
    int maxNum=1e9;
    vector<int> Validity;
    for(int i=2;i<maxNum;i++){
        long long nextValid=((long long)i*i)-2;
        if(nextValid>1e9) break;
        Validity.push_back(int(nextValid));
    }
    // for(int i=0;i<Validity.size();i++) cout<<Validity[i]<<" ";
    // cout<<endl;
    int res=0;
    int prev=(n > 0) ? L[0] : 0;
    int maxDay=0;
    for(int i=1;i<n;i++){
        if(L[i]<prev){
            prev=L[i];
            continue;
        }
        else{
            int diff=L[i]-prev;
            diff++;
            size_t j=0;
            for(j=0;j<Validity.size();j++){
                if(diff<=Validity[j]) break;
            }
            if(j < Validity.size() && diff==Validity[j]){
                diff++;
                j++;
            }
            L[i]=L[i]-diff;
            //cout<<j+1<<" ";
            maxDay=max(maxDay,(int)(j+1)); 
            prev=L[i];
        }
        
    }
    // for(int x:L) cout<<x<<" ";
    //     cout<<endl;
    cout<<maxDay<<endl;
    return 0;
}