#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        
        int dpS = (s[0] == 'u');
        int dpU = 1e9;
        
        for (int i = 1; i < n; i++) {
            int nextS = min(dpS, dpU) + (s[i] == 'u');
            int nextU = 1e9;
            
            if (s[i] == 'u') {
                nextU = dpS;
            }
            
            dpS = nextS;
            dpU = nextU;
        }
        
        cout << dpS << endl;
    }
    return 0;
}