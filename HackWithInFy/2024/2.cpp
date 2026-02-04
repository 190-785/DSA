#include<bits/stdc++.h>
using namespace std;



//This solution is incorrect for the problem statement I thought it was dp 
//and no hero order mattered but actually its a greedy problem

// int main(){
//     long long n,m,h;
//     cin>>n>>m>>h;
//     vector<int> vil(n);
//     long long totalHealthHeroes=m*h;
//     long long totalHealthVillains=0;
//     int elemntGreaterThanHeroes=0;
//     for(int i=0;i<n;i++){ cin>>vil[i];
//         totalHealthVillains+=vil[i];
//         if(vil[i]>h){
//             elemntGreaterThanHeroes=i+1;
//         }
//     }
//     if(totalHealthHeroes>totalHealthVillains){
//         cout<<max(0,elemntGreaterThanHeroes)<<endl;
//     }
//     else{
//         int vilToBeRemoved=0;
//         for(int i=0;i<n;i++){
//             if(totalHealthHeroes>=totalHealthVillains){
//                 break;
//             }
//             totalHealthVillains-=vil[i];
//             vilToBeRemoved++;
//         }
//         cout<<max(vilToBeRemoved,elemntGreaterThanHeroes)<<endl;
//     }
//     return 0;
// }
//My Answer
// int main(){
//     long long n,m,h;
//     cin>>n>>m>>h;
//     vector<long long> vil(n);
//     for(int i=0;i<n;i++){ 
//         cin>>vil[i];
//     }
    
//     long long heroesLeft = m;
//     long long currentHeroHealth = h;
    
//     for(int i=n-1; i>=0; i--){
//         if(vil[i] > h){
//             cout << i+1 << endl;
//             return 0;
//         }
        
//         if(vil[i] <= currentHeroHealth){
//             currentHeroHealth -= vil[i];
//         }
//         else{
//             heroesLeft--;
//             if(heroesLeft <= 0){
//                 cout << i+1 << endl;
//                 return 0;
//             }
//             currentHeroHealth = h - vil[i];
//         }
//     }
    
//     cout << 0 << endl;
//     return 0;
// }


//Step  by step 
